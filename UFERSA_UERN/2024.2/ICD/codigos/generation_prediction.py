import pandas as pd
from neuralprophet import NeuralProphet


def predict_with_neuralprophet(df, power_type, power_capacity=None, weather_element=None):
    m = NeuralProphet()

    columns_renamed = {'data': 'ds', power_type: 'y'}
    if power_type != 'val_carga':
        columns_renamed['val_carga'] = 'val_carga'
        m.add_lagged_regressor('val_carga')
    if power_capacity is not None:
        columns_renamed[power_capacity] = power_capacity
        m.add_lagged_regressor(power_capacity)
    if weather_element is not None:
        columns_renamed[weather_element] = weather_element
        m.add_future_regressor(weather_element)

    history_df = df.rename(columns=columns_renamed)[columns_renamed.values()]
    m.fit(history_df)
    future_df = m.predict(history_df)
    future_df.index = history_df.index

    columns_renamed = {'yhat1': power_type}
    return future_df.rename(columns=columns_renamed)[columns_renamed.values()]


generation_consumption = pd.read_csv(filepath_or_buffer='saidas/consumo-e-geracao.csv', index_col='data',
                                     parse_dates=['data'])
generation_capacity = pd.read_csv(filepath_or_buffer='saidas/capacidade-geracao.csv', index_col='data',
                                  parse_dates=['data'])
climate = pd.read_csv(filepath_or_buffer='saidas/clima/media-brasil.csv', index_col='data', parse_dates=['data'])

concatenated_df = pd.concat(objs=[generation_consumption, generation_capacity, climate], axis=1)
concatenated_df.to_csv('saidas/planilha-concatenada.csv', index=True, index_label='data')

# Prepare dataframe for prediction.
concatenated_df['data'] = concatenated_df.index
# Predict the load.
future_load = predict_with_neuralprophet(concatenated_df, 'val_carga')
concatenated_df['val_carga'] = future_load['val_carga']
# Predict the power.
future_hydro = predict_with_neuralprophet(concatenated_df.copy(), 'val_gerhidraulica', 'potencia_hidraulica', 'chuva')
future_termo = predict_with_neuralprophet(concatenated_df.copy(), 'val_gertermica', 'potencia_termica')
future_wind = predict_with_neuralprophet(concatenated_df.copy(), 'val_gereolica', 'potencia_eolica', 'vento')
future_sun = predict_with_neuralprophet(concatenated_df.copy(), 'val_gersolar', 'potencia_solar', 'sol')

# Concatenate all datasets.
future_power = pd.concat(objs=[future_hydro, future_termo, future_wind, future_sun, future_load], axis=1)
future_power.to_csv(path_or_buf='saidas/previsao-geracao-carga.csv')
