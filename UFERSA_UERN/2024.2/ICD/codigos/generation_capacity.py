import pandas as pd

df = pd.read_csv(filepath_or_buffer='datasets/capacidade-geracao/CAPACIDADE_GERACAO.csv', sep=';',
                 usecols=[6, 14, 15, 16], parse_dates=['dat_entradaoperacao', 'dat_desativacao'])

# Define the date range for the plot.
# START_DATE = df['dat_entradaoperacao'].min()
START_DATE = pd.to_datetime(arg='2000-05-06')
END_DATE = pd.to_datetime(arg='2024-11-30')
# START_DATE = pd.to_datetime('today')

rows = []
# Iterate through the dates.
for current_day in pd.date_range(start=START_DATE, end=END_DATE):

    total_power = 0.0
    hydro_power = 0.0
    thermal_power = 0.0
    wind_power = 0.0
    sun_power = 0.0
    nuclear_power = 0.0

    # Iterate through rows of the dataframe.
    for current_row in df.itertuples():
        if (current_day >= current_row.dat_entradaoperacao) and (
                current_day <= (current_row.dat_desativacao if pd.notna(current_row.dat_desativacao) else END_DATE)):
            total_power += current_row.val_potenciaefetiva

            if current_row.nom_tipousina == 'HIDROELÉTRICA':
                hydro_power += current_row.val_potenciaefetiva
            elif current_row.nom_tipousina == 'TÉRMICA':
                thermal_power += current_row.val_potenciaefetiva
            elif current_row.nom_tipousina == 'EOLIELÉTRICA':
                wind_power += current_row.val_potenciaefetiva
            elif current_row.nom_tipousina == 'FOTOVOLTAICA':
                sun_power += current_row.val_potenciaefetiva
            elif current_row.nom_tipousina == 'NUCLEAR':
                nuclear_power += current_row.val_potenciaefetiva

    rows.append(pd.DataFrame(
        {'data': [current_day], 'potencia_total': [total_power], 'potencia_hidraulica': [hydro_power],
         'potencia_termica': [thermal_power], 'potencia_eolica': [wind_power], 'potencia_solar': [sun_power],
         'potencia_nuclear': [nuclear_power]}))

    print(current_day)

output_df = pd.concat(objs=rows, ignore_index=True)

# Add future dates.
future_values_2028 = pd.DataFrame(
    {'data': [pd.to_datetime(arg='2028-12-31')], 'potencia_total': [253214.0], 'potencia_hidraulica': [108590.0],
     'potencia_termica': [34315.0], 'potencia_eolica': [35214.0], 'potencia_solar': [23309.0],
     'potencia_nuclear': [1990.0]})
output_df = pd.concat(objs=[output_df, future_values_2028], ignore_index=True)

output_df = output_df.set_index('data')
date_range = pd.date_range(start=START_DATE, end='2099-12-31', freq='D')
output_df = output_df.reindex(date_range)
output_df = output_df.interpolate()

output_df.to_csv('saidas/capacidade-geracao.csv', index=True, index_label='data')
