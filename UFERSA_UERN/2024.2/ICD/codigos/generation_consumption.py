from pathlib import Path

import pandas as pd

# Read all files and concatenate them into a single dataframe.
directory = Path('datasets/geracao-consumo/')
df = pd.concat(
    objs=[pd.read_csv(filepath_or_buffer=file, sep=';', index_col='din_instante', usecols=[1, 2, 3, 4, 5, 6, 7],
                      parse_dates=['din_instante']) for file in directory.glob("*.csv")])

# Filter the dataframe to consider only the aggregated rows.
df = df[df['nom_subsistema'] == 'SISTEMA INTERLIGADO NACIONAL']
df = df.drop(columns='nom_subsistema')

# Set the initial and final date of the sequence.
START_DATE = pd.to_datetime(arg='2000-05-06')
END_DATE = pd.to_datetime(arg='2024-11-30')
df = df.loc[(df.index >= START_DATE) & (df.index <= END_DATE)]

# Resample to daily frequency and compute the mean.
daily_df = df.resample('D').mean()

# Fill NaN values.
daily_df = daily_df.interpolate()
# Set NaN values as 0. In this case, only 'val_gereolica' and 'val_gersolar' has NaN values at the initial rows.
daily_df = daily_df.where(daily_df >= 0, 0)

daily_df.to_csv('saidas/consumo-e-geracao.csv', index=True, index_label='data')
