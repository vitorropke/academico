import pandas as pd
from matplotlib import rcParams, pyplot as plt

rcParams['font.family'] = ['Times New Roman']
rcParams['font.size'] = 8

climate = pd.read_csv(filepath_or_buffer='saidas/clima/media-brasil.csv', parse_dates=['data'], index_col='data')
generation_capacity = pd.read_csv(filepath_or_buffer='saidas/capacidade-geracao.csv', parse_dates=['data'],
                                  index_col='data')
generation_load_history = pd.read_csv(filepath_or_buffer='saidas/consumo-e-geracao.csv', parse_dates=['data'],
                                      index_col='data')
generation_load_future = pd.read_csv(filepath_or_buffer='saidas/previsao-consumo-e-geracao.csv', parse_dates=['data'],
                                     index_col='data')

generation_load_future.loc[generation_load_future.index.isin(generation_load_history.index)] = generation_load_history
generation_load = generation_load_future

# Calculate the error.
# Set the initial and final date of the sequence.
# START_DATE = pd.to_datetime(arg='2000-05-06')
# END_DATE = pd.to_datetime(arg='2024-11-30')
# climate_history = climate.loc[(climate.index >= START_DATE) & (climate.index <= END_DATE)]
#
# actual_value = 'vento'
# estimated_value = 'lim_sup_vento'
# difference = climate_history[actual_value] - climate_history[estimated_value]
# print(difference.mean())
# error = difference / climate_history[estimated_value]
# error_percentage = error * 100
# print(error_percentage.mean())

# Pie graph of power matrix.
# selected_date = '2024-11-30'
# power_data_of_that_day = generation_capacity[
#     ['potencia_hidraulica', 'potencia_eolica', 'potencia_termica', 'potencia_solar', 'potencia_nuclear']].loc[
#     selected_date]
# print(power_data_of_that_day)
# fig, ax = plt.subplots()
# ax.pie(power_data_of_that_day, labels=['Hidráulica', 'Eólica', 'Térmica', 'Solar', 'Nuclear'],
#        colors=['cyan', 'lightgreen', 'khaki', 'orange', 'magenta'], autopct='%1.1f%%')
# plt.savefig(fname='saidas/graficos/matriz-energetica.pdf', transparent=True, bbox_inches='tight')

# Plot graph of rain.
# Create a figure with two subplots side by side.
# fig, axes = plt.subplots(1, 2, figsize=(12, 6))  # 1 row, 2 columns
# # Plot the first figure without the shaded area.
# axes[0].plot(climate.index, climate['chuva'], '-')
# axes[0].set_xlabel('Ano')
# axes[0].set_ylabel('Chuva (mm)')
# # Plot the second figure with the shaded area.
# axes[1].plot(climate.index, climate['chuva'], '-')
# axes[1].fill_between(climate.index, climate['lim_inf_chuva'], climate['lim_sup_chuva'], alpha=0.2)
# axes[1].set_xlabel('Ano')
# axes[1].set_ylabel('Chuva (mm)')
# plt.savefig(fname='saidas/graficos/chuva.pdf', transparent=True, bbox_inches='tight')
# Create only one figure.
# plt.plot(climate.index, climate['chuva'], linestyle='-')
# plt.fill_between(climate.index, climate['lim_inf_chuva'], climate['lim_sup_chuva'], alpha=0.2)
#
# # Labels and title.
# plt.xlabel('Ano')
# plt.ylabel('Precipitação (mm)')
# plt.savefig(fname='saidas/graficos/chuva.pdf', transparent=True, bbox_inches='tight')

# Plot graph of sun.
# Create a figure with two subplots side by side.
# fig, axes = plt.subplots(1, 2, figsize=(12, 6))  # 1 row, 2 columns
# # Plot the first figure without the shaded area.
# axes[0].plot(climate.index, climate['sol'], '-')
# axes[0].set_xlabel('Ano')
# axes[0].set_ylabel('Sol (KJ/m²)')
# # Plot the second figure with the shaded area.
# axes[1].plot(climate.index, climate['sol'], '-')
# axes[1].fill_between(climate.index, climate['lim_inf_sol'], climate['lim_sup_sol'], alpha=0.2)
# axes[1].set_xlabel('Ano')
# axes[1].set_ylabel('Sol (KJ/m²)')
# plt.savefig(fname='saidas/graficos/sol.pdf', transparent=True, bbox_inches='tight')
# Create only one figure.
# plt.plot(climate.index, climate['sol'], linestyle='-')
# plt.fill_between(climate.index, climate['lim_inf_sol'], climate['lim_sup_sol'], alpha=0.2)
#
# # Labels and title.
# plt.xlabel('Ano')
# plt.ylabel('Radiação solar (KJ/m²)')
# plt.savefig(fname='saidas/graficos/sol.pdf', transparent=True, bbox_inches='tight')

# Plot graph of wind.
# Create a figure with two subplots side by side.
# fig, axes = plt.subplots(1, 2, figsize=(12, 6))  # 1 row, 2 columns
# # Plot the first figure without the shaded area.
# axes[0].plot(climate.index, climate['vento'], '-')
# axes[0].set_xlabel('Ano')
# axes[0].set_ylabel('Vento (m/s)')
# # Plot the second figure with the shaded area.
# axes[1].plot(climate.index, climate['vento'], '-')
# axes[1].fill_between(climate.index, climate['lim_inf_vento'], climate['lim_sup_vento'], alpha=0.2)
# axes[1].set_xlabel('Ano')
# axes[1].set_ylabel('Vento (m/s)')
# plt.savefig(fname='saidas/graficos/vento.pdf', transparent=True, bbox_inches='tight')
# Create only one figure.
# plt.plot(climate.index, climate['vento'], linestyle='-')
# plt.fill_between(climate.index, climate['lim_inf_vento'], climate['lim_sup_vento'], alpha=0.2)
#
# # Labels and title.
# plt.xlabel('Ano')
# plt.ylabel('Velocidade do vento (m/s)')
# plt.savefig(fname='saidas/graficos/Fig6.pdf', transparent=True, bbox_inches='tight')

# Plot graph of generation capacity.
# plt.plot(generation_capacity.index, generation_capacity['potencia_total'], color='black', label='Total', linestyle='-')
# plt.plot(generation_capacity.index, generation_capacity['potencia_hidraulica'], color='cyan', label='Hidráulica', linestyle='-')
# plt.plot(generation_capacity.index, generation_capacity['potencia_eolica'], color='lightgreen', label='Eólica', linestyle='-')
# plt.plot(generation_capacity.index, generation_capacity['potencia_termica'], color='khaki', label='Térmica', linestyle='-')
# plt.plot(generation_capacity.index, generation_capacity['potencia_solar'], color='orange', label='Fotovoltaica', linestyle='-')
# plt.plot(generation_capacity.index, generation_capacity['potencia_nuclear'], color='magenta', label='Nuclear', linestyle='-')
#
# # Labels and title.
# plt.xlabel('Ano')
# plt.ylabel('Potência (MW)')
# plt.legend(loc='best', fontsize='small')
# plt.savefig(fname='saidas/graficos/Fig7.pdf', transparent=True, bbox_inches='tight')

# Plot graph of generation and consumption.
# plt.plot(generation_load.index, generation_load['val_carga'], color='gray', label='Consumo', linestyle='-')
# plt.plot(generation_load.index, generation_load['val_gerhidraulica'], color='cyan', label='Hidráulica', linestyle='-')
# plt.plot(generation_load.index, generation_load['val_gereolica'], color='lightgreen', label='Eólica', linestyle='-')
# plt.plot(generation_load.index, generation_load['val_gertermica'], color='khaki', label='Térmica', linestyle='-')
# plt.plot(generation_load.index, generation_load['val_gersolar'], color='orange', label='Fotovoltaica', linestyle='-')
#
# # Labels and title.
# plt.xlabel('Ano')
# plt.ylabel('Potência (MW)')
# plt.legend(loc='best', fontsize='small')
# plt.savefig(fname='saidas/graficos/Fig8.pdf', transparent=True, bbox_inches='tight')

# Plot graph of generation capacity, instant generation and consumption.
plt.plot(generation_capacity.index, generation_capacity['potencia_total'], color='black', label='Cap. Total', linestyle='-')
plt.plot(generation_load.index, generation_load['val_carga'], color='gray', label='Consumo', linestyle='-')

plt.plot(generation_capacity.index, generation_capacity['potencia_hidraulica'], color='blue', label='Cap. Hidráulica', linestyle='-')
plt.plot(generation_load.index, generation_load['val_gerhidraulica'], color='cyan', label='Ger. Hidráulica', linestyle='-')

plt.plot(generation_capacity.index, generation_capacity['potencia_eolica'], color='green', label='Cap. Eólica', linestyle='-')
plt.plot(generation_load.index, generation_load['val_gereolica'], color='lightgreen', label='Ger. Eólica', linestyle='-')

plt.plot(generation_capacity.index, generation_capacity['potencia_termica'], color='brown', label='Cap. Térmica', linestyle='-')
plt.plot(generation_load.index, generation_load['val_gertermica'], color='khaki', label='Ger. Térmica', linestyle='-')

plt.plot(generation_capacity.index, generation_capacity['potencia_solar'], color='red', label='Cap. Fotovoltaica', linestyle='-')
plt.plot(generation_load.index, generation_load['val_gersolar'], color='orange', label='Ger. Fotovoltaica', linestyle='-')

# Labels and title.
plt.xlabel('Ano')
plt.ylabel('Potência (MW)')
plt.legend(loc='best', fontsize='small')
plt.savefig(fname='saidas/graficos/Fig9.pdf', transparent=True, bbox_inches='tight')
