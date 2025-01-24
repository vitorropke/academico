from collections import defaultdict
from pathlib import Path

import numpy as np
import pandas as pd
from prophet import Prophet

ROOT_INPUT_DIRECTORY = Path('datasets/clima')
ROOT_OUTPUT_DIRECTORY = Path('saidas/clima/futuro-de-cada-estacao')


def calculate_mean_weather_stations():
    dfs = [pd.read_csv(filepath_or_buffer=file, index_col='data', parse_dates=['data']) for file in
           ROOT_OUTPUT_DIRECTORY.glob("*.csv")]
    concatenated_df = pd.concat(objs=dfs)

    mean_df = concatenated_df.groupby('data').mean()
    mean_df.to_csv(path_or_buf=ROOT_OUTPUT_DIRECTORY.parent.joinpath('media-brasil.csv'), index=True)


def predict_climate(df, weather_station):
    # Resample to daily frequency and compute the mean.
    daily_df = df.resample('D').mean()
    daily_df['instante'] = daily_df.index

    # Predict weather elements.
    rain_forecast = predict_element(daily_df, 'chuva')
    sun_forecast = predict_element(daily_df, 'sol')
    wind_forecast = predict_element(daily_df, 'vento')

    # Concatenate the three weather elements.
    all_forecasts = pd.concat(objs=[rain_forecast, sun_forecast, wind_forecast], axis=1)
    all_forecasts.to_csv(path_or_buf=ROOT_OUTPUT_DIRECTORY.joinpath(weather_station))


def predict_element(df, weather_element):
    columns_renamed = {'instante': 'ds', weather_element: 'y'}
    history_df = df.rename(columns=columns_renamed)[columns_renamed.values()]

    m = Prophet()
    m.fit(history_df)
    future = m.make_future_dataframe(periods=(2100 - 2024) * 365 - 316)
    future_df = m.predict(future)
    future_df.index = history_df.index

    columns_renamed = {'yhat_lower': 'lim_inf_' + weather_element, 'yhat': weather_element,
                       'yhat_upper': 'lim_sup_' + weather_element}
    return future_df.rename(columns=columns_renamed)[columns_renamed.values()]


def group_date_by_weather_station():
    # Dictionary to group files by weather station.
    weather_stations = defaultdict(list)

    # Iterate through year directories.
    for year_dir in ROOT_INPUT_DIRECTORY.iterdir():
        if year_dir.is_dir() and year_dir.name.isdigit():
            for file_path in year_dir.glob("INMET*.CSV"):
                # Extract weather station identifier (e.g., INMET_CO_DF_A001_BRASILIA).
                station_id = "_".join(file_path.stem.split("_")[:5])
                weather_stations[station_id].append(file_path)

    # Concatenate files for each weather station into a single dataframe.
    for station_id, files in weather_stations.items():
        # Sort paths to ensure chronological order and read them.
        files.sort()
        dfs = [pd.read_csv(filepath_or_buffer=file, sep=';', names=['data', 'hora', 'chuva', 'sol', 'vento'],
                           usecols=[0, 1, 2, 6, 18], skiprows=9, decimal=',', encoding='latin1') for file in files]
        concatenated_df = pd.concat(objs=dfs, ignore_index=True)

        # Create datetime column and remove timezones.
        datetime = concatenated_df.pop('data') + ' ' + concatenated_df.pop('hora')
        datetime_format1 = pd.to_datetime(arg=datetime, errors='coerce', format='%Y-%m-%d %H:%M')
        datetime_format2 = pd.to_datetime(arg=datetime, errors='coerce', format='%Y/%m/%d %H%M %Z').dt.tz_localize(None)
        concatenated_df['instante'] = datetime_format1.fillna(datetime_format2)

        # Save only if the station has at least 3 files (to collect enough data for prediction).
        if len(files) < 3:
            print(
                f"Insufficient timeseries for {station_id} with only {len(files)} file(s). Not saving the concatenated file.")
        else:
            file_name_to_save = 'datasets/clima/estacoes-automaticas-agrupadas/' + station_id + '.csv'
            concatenated_df.to_csv(path_or_buf=file_name_to_save, index=False)
            print(f"Processed {station_id} with {len(files)} files. Saving concatenated file.")


def preprocess_and_predict(df, station_id):
    # Consider values below 0 as NaN.
    selected_columns = ['chuva', 'sol', 'vento']
    df[selected_columns] = df[selected_columns].where(df[selected_columns] >= 0, np.nan)

    # Skip if there's too much NaN values.
    nan_percentage = df.isna().mean() * 100
    columns_above_70_nan = nan_percentage[nan_percentage > 70]
    if not columns_above_70_nan.empty:
        print(f"Too much NaN values in {station_id}. Skipping.")
        return

    # Skip if there's too much near 0 values, except for 'chuva' column.
    near_zero_percentage = (df[['sol', 'vento']] < 0.2).sum() / df[['sol', 'vento']].notna().sum() * 100
    columns_above_70_near_zero = near_zero_percentage[near_zero_percentage > 70]
    if not columns_above_70_near_zero.empty:
        print(f"Too much 0 values in {station_id}. Skipping.")
        return

    # Only predict if the data range is greater than 2 years.
    days_range = (df.index.max() - df.index.min()).days
    if days_range >= 730:
        print(f"Predicting climate for {station_id}. Range of {days_range} days.")
        predict_climate(df, station_id)
    else:
        print(f"Not enough data range ({days_range} days). Not predicting the climate of {station_id}.")


def read_from_bdmep():
    for file in ROOT_INPUT_DIRECTORY.glob("estacoes-automaticas/*.csv"):
        # Input format (dados_A003_H_2001-05-24_2024-11-30.csv).
        station_id = file.stem.split("_")[1] + '.csv'
        if ROOT_OUTPUT_DIRECTORY.joinpath(station_id).exists():
            print(f"Prediction for {station_id} already exists. Skipping.")
            continue

        df = pd.read_csv(filepath_or_buffer=file, sep=';', names=['data', 'hora', 'chuva', 'sol', 'vento'],
                         index_col=False, skiprows=11, parse_dates={'instante': [0, 1]}, decimal=',')
        df = df.set_index('instante')

        preprocess_and_predict(df, station_id)


def read_from_grouped_weather_stations():
    for file in ROOT_INPUT_DIRECTORY.glob("estacoes-automaticas-agrupadas/*.csv"):
        # Input format (INMET_CO_DF_A001_BRASILIA.csv).
        station_id = file.stem.split("_")[3] + '.csv'
        if ROOT_OUTPUT_DIRECTORY.joinpath(station_id).exists():
            print(f"Prediction for {station_id} already exists. Skipping.")
            continue

        df = pd.read_csv(filepath_or_buffer=file, index_col=['instante'], parse_dates=['instante'])

        preprocess_and_predict(df, station_id)


calculate_mean_weather_stations()
