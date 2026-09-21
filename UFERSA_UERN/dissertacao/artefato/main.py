import time
from pathlib import Path

import pandas as pd
from pandas import DataFrame, Series

from clustering_operations import perform_clustering, perform_subclustering
from connection_operations import find_hubs, create_cycles
from gtfs_operations import generate_gtfs
from metaheuristic_operations import calculate_costs, perform_optimization
from preprocessing_operations import rm_too_close_points, scale_the_data, pop_central_point
from visualization_operations import generate_interactive_map, generate_static_map, set_colors_for_points, \
    convert_point_names_to_coords


def generate_maps(inst: DataFrame, major_hub: str, hubs: list[str], cycles: list[list[list[str]]],
                  filename: str) -> None:
    hub_coords: list[tuple[float, float]]
    cycle_coords: list[list[list[tuple[float, float]]]]
    hub_coords, cycle_coords = convert_point_names_to_coords(inst=inst, hubs=hubs, cycles=cycles)
    colors: dict[tuple[float, float], str] = set_colors_for_points(cycles=cycle_coords)

    print()
    print('Gerando mapas.')
    Path(filename).mkdir(parents=True, exist_ok=True)
    generate_interactive_map(inst=inst, major_hub=major_hub, hubs=hub_coords, cycles=cycle_coords, colors=colors,
                             filepath=f'{filename}/interactive_map')
    generate_static_map(inst=inst, major_hub=major_hub, hubs=hub_coords, cycles=cycle_coords, colors=colors,
                        filepath=f'{filename}/static_map')


def main(random_state: int) -> None:
    start_time: float = time.process_time()

    print('Lendo instância.')
    inst: DataFrame = pd.read_csv(filepath_or_buffer='input/od_matrix.csv', index_col='point')

    print()
    print('Pré-processando.')
    inst = rm_too_close_points(inst=inst, distance_threshold=50)

    inst_without_major_hub: DataFrame
    initial_major_hub: str
    inst_without_major_hub, initial_major_hub = pop_central_point(inst=inst)

    scaled_inst: DataFrame = scale_the_data(inst=inst_without_major_hub, population_influence_factor=1.0)

    print()
    print('Agrupando.')
    clusters: Series = perform_clustering(inst=scaled_inst)
    inst_without_major_hub['cluster'] = clusters
    scaled_inst['cluster'] = clusters

    subclusters: Series = pd.Series(dtype='int32')
    # min_num_points_per_subcluster: int = int(input('Digite o número mínimo de paradas por subcluster desejado: '))
    # max_num_points_per_subcluster: int = int(input('Digite o número máximo de paradas por subcluster desejado: '))
    min_num_points_per_subcluster: int = 30
    max_num_points_per_subcluster: int = 40

    # If min and max restrictions are mathematically impossible to generate clusters, this code will expand the range.
    failed_subclustering: bool = True
    while failed_subclustering:
        try:
            subclusters: Series = perform_subclustering(inst=scaled_inst,
                                                        min_num_points_per_subcluster=min_num_points_per_subcluster,
                                                        max_num_points_per_subcluster=max_num_points_per_subcluster,
                                                        random_state=random_state)
            failed_subclustering = False
        except ValueError:
            print('Expandindo limites.')
            min_num_points_per_subcluster -= 1
            max_num_points_per_subcluster += 1

    inst_without_major_hub['subcluster'] = subclusters

    print()
    print('Gerando solução.')
    initial_hubs: list[str] = find_hubs(inst=inst_without_major_hub)
    initial_cycles: list[list[list[str]]] = create_cycles(inst=inst_without_major_hub, hubs=initial_hubs)

    map_path: str = f'outputs/maps/map_{random_state}'

    # generate_maps(inst=inst, major_hub=initial_major_hub, hubs=initial_hubs, cycles=initial_cycles,
    #               filename=f'{map_path}/initial_solution')

    print()
    print('Otimizando solução.')
    final_major_hub: str
    final_hubs: list[str]
    final_cycles: list[list[list[str]]]
    min_num_points_per_cycle: int = min_num_points_per_subcluster - 1
    max_num_points_per_cycle: int = max_num_points_per_subcluster + 1
    # final_major_hub, final_hubs, final_cycles = perform_optimization(inst=inst, major_hub=initial_major_hub,
    #                                                                  cycles=initial_cycles,
    #                                                                  min_num_points_per_cycle=min_num_points_per_cycle,
    #                                                                  max_num_points_per_cycle=max_num_points_per_cycle,
    #                                                                  random_state=random_state)
    final_major_hub = 'parada_Teatro_Municipal_Dix_Huit_Rosado'
    final_hubs = ['parada_Travessa_Francisco_Cavalcante_de_Moura_Ida0', 'parada_UFERSA_Ida', 'parada_Avenida_da_Integracao_Ida1', 'parada_Nossa_Corretora_de_Seguros']
    final_cycles = [[['parada_Travessa_Francisco_Cavalcante_de_Moura_Ida0', 'parada_Rua_Francisco_Lima_Ferreira_Ida0', 'parada_Churrascaria_Chimarrao_Ida', 'parada_Rua_Francisco_Lima_Ferreira_Volta0', 'parada_Avenida_Damiao_Rodrigues_de_Souza_Volta0', 'parada_UBS_Vereador_Lahyre_Rosado_Volta', 'parada_Rua_Manoel_Batista_Neto_Volta0', 'parada_Rua_Manoel_Batista_Neto_Volta1', 'parada_Avenida_Gagaca_Lopes_Volta0', 'parada_Ida_Volta_Linha8', 'parada_Avenida_Francisco_de_Assis_Fontes_Ida0', 'parada_Avenida_Gagaca_Lopes_Ida0', 'parada_Avenida_Gagaca_Lopes_Ida1', 'parada_Rua_Joao_Barbosa_de_Lira_Ida0', 'parada_Rua_Joao_Barbosa_De_Lira_Volta0', 'parada_Rua_Manoel_Amancio_Reboucas_Neto_Ida0', 'parada_Ida_Volta_Linha7', 'parada_Rua_Sem_Nome_Jardim_das_Palmeiras_Ida0', 'parada_Rua_Sem_Nome_Jardim_das_Palmeiras_Ida1', 'parada_Rua_Sem_Nome_Jardim_das_Palmeiras_Ida2', 'parada_Rua_Professor_Anderson_Araujo_Ida0', 'parada_Rua_Professor_Anderson_Araujo_Volta0', 'parada_Avenida_Antonio_Bento_Ida0', 'parada_Avenida_Antonio_Bento_Ida1', 'parada_Avenida_Antonio_Bento_Ida2', 'parada_Avenida_Antonio_Bento_Ida3', 'parada_Avenida_Antonio_Bento_Ida4', 'parada_Avenida_Antonio_Bento_Volta3', 'parada_Avenida_Antonio_Bento_Volta2', 'parada_Avenida_Antonio_Bento_Volta1', 'parada_Assembleia_de_Deus_Congregacao_Liberdade_II_Ida', 'parada_Avenida_Antonio_Bento_Volta0', 'parada_Assembleia_de_Deus_Ministerio_de_Madureira_Ida', 'parada_Campo_das_Malvinas', 'parada_Rua_Ieda_Rodrigues_Rocha_Volta0', 'parada_BR_304_Sul_Ida0', 'parada_Clube_da_Caixa', 'parada_Avenida_Desembargador_Olavo_Maia_Ida0', 'parada_Rua_Manoel_Amancio_Reboucas_Neto_Ida1', 'parada_Avenida_Desembargador_Olavo_Maia_Ida1', 'parada_Avenida_Desembargador_Olavo_Maia_Ida2', 'parada_Travessa_Francisco_Cavalcante_de_Moura_Ida0'], ['parada_Travessa_Francisco_Cavalcante_de_Moura_Ida0', 'parada_Avenida_Pedro_Paraguai_Volta0', 'parada_UBS_da_Familia_Pereira_Francisco_de_Azevedo_Volta', 'parada_Rua_Armando_Duarte_Numero_Volta0', 'parada_Avenida_Mossoro_Volta0', 'parada_Avenida_Mossoro_Volta1', 'parada_Avenida_Mossoro_Volta3', 'parada_Ida_Volta_Linha19', 'parada_Avenida_Mossoro_Ida0', 'parada_Avenida_Mossoro_Ida1', 'parada_RN_117_Ida0', 'parada_RN_117_Ida1', 'parada_Elfe_Operacao_E_Manutencao_Ida', 'parada_Sabao_Guarani_Ida', 'parada_Assembleia_de_Deus_Efraim_1_Ida', 'parada_Posto_da_Policia_Rodoviaria_Estadual_RN_117_Ida', 'parada_RN_117_Ida2', 'parada_RN_117_Volta0', 'parada_Rua_Januario_Granjeiro_Volta0', 'parada_Rua_Januario_Granjeiro_Ida0', 'parada_Rua_Antonio_Geraldo_de_Medeiros_Ida0', 'parada_Rua_Nilza_Pires_de_Almeida_Ida0', 'parada_Rua_Josefa_Xavier_de_Medeiros_Ida0', 'parada_Rua_Manoel_Balbino_da_Costa_Ida0', 'parada_Rua_Zeus_Volta0', 'parada_Rua_Zeus_Volta1', 'parada_Rua_Zeus_Ida1', 'parada_Rua_Zeus_Ida0', 'parada_Rua_Zeus_Volta4', 'parada_Ida_Volta_Linha9', 'parada_Travessa_Francisco_Cavalcante_de_Moura_Ida0']], [['parada_UFERSA_Ida', 'parada_Tenda_Restaurante', 'parada_Avenida_Francisco_Mota_Ida2', 'parada_EE_Jose_de_Freitas_Nobre', 'parada_Avenida_Francisco_Mota_Ida1', 'parada_Assembleia_de_Deus_Arraial_1', 'parada_Avenida_Francisco_Mota_Ida0', 'parada_Avenida_Francisco_Mota_Volta0', 'parada_UNIRB_Ida', 'parada_BR_110_Norte_Ida0', 'parada_Condominio_Ecoville_Ida', 'parada_Taldi_Engenharia_Ida', 'parada_Condominio_Ninho_Residencial_Ida', 'parada_Rua_Raimundo_Almeida_Lopes_Ida0', 'parada_Rua_Raimundo_Almeida_Lopes_Ida1', 'parada_Rua_Raimundo_Almeida_Lopes_Ida2', 'parada_Rua_Raimundo_Almeida_Lopes_Ida3', 'parada_Rua_Maria_Rosa_de_Araujo_Ida0', 'parada_Rua_Maria_Rosa_de_Araujo_Ida1', 'parada_Rua_Maria_Rosa_de_Araujo_Ida2', 'parada_Rua_Sergina_Lucinda_Alves_Volta0', 'parada_Rua_Sergina_Lucinda_Alves_Volta1', 'parada_Rua_Sergina_Lucinda_Alves_Volta2', 'parada_BR_110_Norte_Volta0', 'parada_Leite_Do_Sertao_Ida', 'parada_Rua_Joao_Falcao_Ida0', 'parada_Avenida_Joaquim_da_Silveira_Borges_Volta0', 'parada_Pizzaria_Do_Louro_Ida', 'parada_Rua_Andre_Pedro_Fernandes_Volta0', 'parada_Rua_Andre_Pedro_Fernandes_Ida1', 'parada_UFERSA_Ida'], ['parada_UFERSA_Ida', 'parada_UFERSA_Volta', 'parada_Ministerio_Publico_da_Uniao_Ida', 'parada_UFERSA_Lateral_Ida', 'parada_Convesti', 'parada_Alameda_das_Carnaubeiras_Ida0', 'parada_Alameda_das_Carnaubeiras_Volta0', 'parada_Forum_Desembargador_Silveira_Martins', 'parada_ASSUFERSA_Ida', 'parada_Rua_dos_Cajueiros_Ida0', 'parada_Ministerio_Publico_Estadual_Ida', 'parada_Alameda_das_Chacaras_Ida0', 'parada_Praca_do_Bicicross_Ida', 'parada_IFRN_Ida', 'parada_Supermercados_Queiroz_Dom_Jaime_Camara_Ida', 'parada_Rua_Raimundo_Firmino_de_Oliveira_Ida0', 'parada_Avenida_Presidente_Dutra_Ida0', 'parada_Rua_Pedro_Valamira_Fernandes_Volta0', 'parada_FACENE_Ida', 'parada_Rua_Presidente_Cafe_Filho_Volta2', 'parada_Rua_Presidente_Cafe_Filho_Volta1', 'parada_Rua_Presidente_Cafe_Filho_Volta0', 'parada_Oeste_Trigo', 'parada_Mercadinho_Cocada', 'parada_CITECS', 'parada_Regina_Veiculos_Multimarcas', 'parada_Rua_Alfredo_Ananias_Volta0', 'parada_Farmacia_da_familia', 'parada_Pousada_Mossoro', 'parada_Estacao_Fitness', 'parada_Residencial_Vingt_Un_Rosado_Ida', 'parada_Costalarga_Corretora_de_Seguros_Presidente_Costa_e_Silva_Ida', 'parada_Cristais_do_Alto_Ida', 'parada_ADUERN_Ida', 'parada_UFERSA_Ida'], ['parada_UFERSA_Ida', 'parada_Delegacia', 'parada_Locavelthe', 'parada_Avenida_Servulo_Marcelino_Volta0', 'parada_Avenida_Servulo_Marcelino_Volta1', 'parada_Avenida_Alberto_Maranhao_Sul_Ida0', 'parada_Avenida_Alberto_Maranhao_Sul_Ida1', 'parada_Multmoveis_Ida', 'parada_Posto_BH', 'parada_Avenida_Alberto_Maranhao_Sul_Ida2', 'parada_Delta_Gas_Ida', 'parada_Avenida_Alberto_Maranhao_Sul_Ida3', 'parada_Avenida_Alberto_Maranhao_Sul_Volta0', 'parada_Avenida_Alberto_Maranhao_Sul_Volta2', 'parada_Rua_Vicente_Martins_Ida0', 'parada_Rua_Vicente_Martins_Volta0', 'parada_Rua_Dom_Helder_Camara_Ida0', 'parada_Rua_Marinho_Dantas_Ida0', 'parada_Supermercado_Reboucas_Belo_Horizonte_Ida', 'parada_Rua_Zeca_Medeiros_Ida0', 'parada_Rua_Zeca_Medeiros_Volta0', 'parada_Rua_Souza_Leao_Ida0', 'parada_UPA_Raimundo_Benjamin_Franco_Ida', 'parada_EE_Monsenhor_Raimundo_Gurgel_Ida', 'parada_Rua_Professor_Manuel_Freire_Ida0', 'parada_Rua_Chico_Linhares_Volta0', 'parada_UPA_Alto_de_Sao_Manoel_Volta', 'parada_Green_Garden_Residence_Club_Volta', 'parada_Panificadora_Bom_dia', 'parada_Santorini_Restaurante_Mossoro', 'parada_Lino_Brita', 'parada_UFERSA_Ida'], ['parada_UFERSA_Ida', 'parada_UERN_Ida', 'parada_Rua_Francisco_Soares_Xaxa_Ida1', 'parada_Rua_Francisco_Soares_Xaxa_Ida0', 'parada_Rua_Monalisa_Fartura_Ida0', 'parada_Rua_Monalisa_Fartura_Ida1', 'parada_Ida_Volta_Linha17', 'parada_Rua_Joao_Aquino_de_Morais_Volta1', 'parada_Rua_Pedro_Zaqueu_Dantas_Ida0', 'parada_Ida_Volta_Linha5', 'parada_Avenida_Luiz_Marques_Volta0', 'parada_Rua_Hamilton_Freire_de_Andrade_Volta1', 'parada_Rua_Hamilton_Freire_de_Andrade_Volta0', 'parada_Rua_Rosemiro_Fontes_Carneiro_Ida0', 'parada_Salao_do_Reino_das_Testemunhas_de_Jeova_Vingt_Rosado', 'parada_EE_Jeronimo_Vingt_Rosado_Maia', 'parada_Igreja_Sagrada_Familia_Ida', 'parada_Rua_Francisco_Bandeira_Sobrinho_Ida0', 'parada_Rua_Francisco_Bandeira_Sobrinho_Volta0', 'parada_Avenida_Doutor_Epitacio_Carvalho_Ida0', 'parada_Avenida_Doutor_Epitacio_Carvalho_Volta0', 'parada_Bioforma_Academia_Ida', 'parada_Rua_Professora_Maria_Zelia_Ferreira_Guerra_Ida0', 'parada_Rua_Professora_Maria_Zelia_Ferreira_Guerra_Ida1', 'parada_Rua_Professora_Maria_Zelia_Ferreira_Guerra_Volta0', 'parada_Praca_do_Vingt_Rosado', 'parada_Rua_Andre_Pedro_Fernandes_Ida0', 'parada_Avenida_Joaquim_da_Silveira_Borges_Ida0', 'parada_Rua_da_Pitomba_Volta0', 'parada_Rua_do_Pinhao_Volta1', 'parada_Rua_do_Pinhao_Volta0', 'parada_UFERSA_Ida']], [['parada_Avenida_da_Integracao_Ida1', 'parada_Avenida_Sao_Jeronimo_Ida1', 'parada_Avenida_Sao_Jeronimo_Ida2', 'parada_Avenida_Sao_Jeronimo_Volta1', 'parada_Avenida_Sao_Jeronimo_Volta0', 'parada_Avenida_Santa_Luzia_Ida0', 'parada_Avenida_Santa_Luzia_Ida1', 'parada_Avenida_Santa_Luzia_Ida2', 'parada_Avenida_Santa_Luzia_Ida3', 'parada_Avenida_Presidente_Costa_e_Silva_Volta1', 'parada_Avenida_Presidente_Costa_e_Silva_Volta2', 'parada_Avenida_Presidente_Costa_e_Silva_Volta3', 'parada_Assembleia_de_Deus_Abolicao_IV_Ida', 'parada_Avenida_Presidente_Costa_e_Silva_Ida4', 'parada_Igreja_Adventista_do_Setimo_Dia_Abolicao_Ida', 'parada_Avenida_Presidente_Costa_e_Silva_Ida3', 'parada_Avenida_Presidente_Costa_e_Silva_Ida2', 'parada_Igreja_de_Sao_Pedro_Ida', 'parada_Igreja_Universal_do_Reino_de_Deus_Abolicao_Ida', 'parada_Rua_Antonio_Vitor_de_Melo_Ida0', 'parada_Igreja_Evangelica_Avivamento_Biblico_Abolicao_III_Ida', 'parada_Supermercado_Queiroz_Santa_Delmira_Ida', 'parada_Avenida_Santa_Luzia_Volta0', 'parada_Avenida_Santa_Luzia_Volta1', 'parada_Avenida_Santa_Luzia_Volta2', 'parada_Avenida_Santa_Luzia_Volta3', 'parada_Avenida_Sao_Jeronimo_Ida0', 'parada_Assembleia_de_Deus_do_Parque_das_Rosas_Ida', 'parada_Avenida_da_Integracao_Volta0', 'parada_Avenida_da_Integracao_Ida1'], ['parada_Avenida_da_Integracao_Ida1', 'parada_Igreja_Universal_Integracao_Ida', 'parada_Rua_Senador_Ruy_Carneiro_Volta0', 'parada_Rua_Senador_Ruy_Carneiro_Ida0', 'parada_Ida_Volta_Linha1_Linha2', 'parada_Comercial_Gerdau_Ida', 'parada_Avenida_Presidente_Costa_e_Silva_Volta0', 'parada_Igreja_de_Sao_Francisco_de_Assis_Abolicao_Ida', 'parada_Rua_Tarcisio_Correia_Ida0', 'parada_Lonam_Freios_Pecas_e_Servicos_Volta', 'parada_Rua_Celso_Rego_Volta0', 'parada_Rua_Celso_Rego_Volta1', 'parada_Posto_De_Molas_Scooby_Volta', 'parada_EBS_Perfuracoes_Volta', 'parada_3_Coracoes_Ida', 'parada_Avenida_dos_Automoveis_Ida0', 'parada_Avenida_dos_Automoveis_Ida1', 'parada_Avenida_dos_Automoveis_Ida2', 'parada_Avenida_dos_Automoveis_Ida3', 'parada_Rua_Centro_Esportivo_Mossoroense_Volta0', 'parada_Rua_Centro_Esportivo_Mossoroense_Volta1', 'parada_Ida_Volta_Linha12', 'parada_Jodiesel_Volta', 'parada_Capela_de_Nossa_Senhora_Aparecida_Ida', 'parada_EM_Alcides_Manoel_de_Medeiros_Ida', 'parada_Rua_Francisco_Gomes_Monteiro_Ida0', 'parada_EE_Diran_Ramos_do_Amaral_Ida', 'parada_Rua_Sem_Nome_Santa_Julia_Ida3', 'parada_Rua_Sem_Nome_Santa_Julia_Ida2', 'parada_Avenida_da_Integracao_Ida0', 'parada_Avenida_da_Integracao_Ida1'], ['parada_Avenida_da_Integracao_Ida1', 'parada_Rua_Sem_Nome_Santa_Julia_Ida1', 'parada_Rua_Elita_Rodrigues_Ida0', 'parada_Rua_Sem_Nome_Santa_Julia_Ida4', 'parada_Rua_Sem_Nome_Santa_Julia_Ida0', 'parada_Rua_Antonia_das_Merces_Reinaldo_Ida0', 'parada_Rua_Antonia_das_Merces_Reinaldo_Ida1', 'parada_Avenida_Benjamin_Soares_Cardoso_Volta4', 'parada_Avenida_Benjamin_Soares_Cardoso_Volta5', 'parada_Avenida_Benjamin_Soares_Cardoso_Volta6', 'parada_Ida_Volta_Linha4', 'parada_Rua_Expedicionario_Claudionor_Amancio_de_Oliveira_Ida0', 'parada_Rua_Expedicionario_Claudionor_Amancio_de_Oliveira_Ida1', 'parada_Rua_Expedicionario_Claudionor_Amancio_de_Oliveira_Ida2', 'parada_Praca_Abolicao_V_Ida0', 'parada_Praca_Abolicao_V_Ida1', 'parada_Avenida_Benjamin_Soares_Cardoso_Ida0', 'parada_Avenida_Benjamin_Soares_Cardoso_Ida1', 'parada_Avenida_Benjamin_Soares_Cardoso_Ida2', 'parada_Avenida_Benjamin_Soares_Cardoso_Volta1', 'parada_Avenida_Benjamin_Soares_Cardoso_Volta0', 'parada_Avenida_Benjamin_Soares_Cardoso_Ida3', 'parada_Avenida_Benjamin_Soares_Cardoso_Ida4', 'parada_Avenida_Senador_Petronio_Portela_Ida0', 'parada_Avenida_Senador_Petronio_Portela_Volta1', 'parada_Avenida_Senador_Petronio_Portela_Ida1', 'parada_Avenida_Senador_Petronio_Portela_Ida3', 'parada_Avenida_Senador_Petronio_Portela_Volta0', 'parada_Avenida_Senador_Petronio_Portela_Ida5', 'parada_Avenida_Presidente_Costa_e_Silva_Ida0', 'parada_Avenida_Presidente_Costa_e_Silva_Ida1', 'parada_Rua_Francisco_Alves_da_Silva_Ida0', 'parada_Avenida_da_Integracao_Ida1']], [['parada_Nossa_Corretora_de_Seguros', 'parada_Central', 'terminal_Praca_Felipe_Guerra', 'parada_Caixa_Economica_Federal', 'parada_Oficinas', 'parada_Rua_Nisia_Floresta_Ida3', 'parada_Rua_Nisia_Floresta_Ida2', 'parada_Rua_Nisia_Floresta_Ida1', 'parada_Avenida_Rio_Branco_Sul0', 'parada_Avenida_Rio_Branco_Sul1', 'parada_Avenida_Rio_Branco_Sul2', 'parada_A_Construtora_Express', 'parada_Rua_Coelho_Neto_Ida1', 'parada_Ster_Bom_Loja_da_Fabrica_Ida', 'parada_Praca_da_Igreja_de_Nossa_Senhora_da_Conceicao_Ida', 'parada_Churrascaria_Mossoro', 'parada_Rua_Antonio_Reis_Ida0', 'parada_Mercado_Publico_do_Alto_da_Conceicao', 'parada_Paozao', 'parada_Rua_Coelho_Neto_Ida2', 'parada_Rua_Coelho_Neto_Ida3', 'parada_Friotec', 'parada_Avenida_Cunha_da_Mota0', 'parada_Avenida_Cunha_da_Mota1', 'parada_AeC', 'parada_Izamar_Supermercado', 'parada_Fic_Frio_Alto_de_Sao_Manoel', 'parada_JPL_Motos_Ilha_de_Santa_Luzia_Ida', 'parada_Hotel_VillaOeste_Ida', 'parada_Nossa_Corretora_de_Seguros'], ['parada_Nossa_Corretora_de_Seguros', 'parada_Avenida_Joao_da_Escossia_Volta1', 'parada_Splendore_Residence_Volta', 'parada_Fic_Frio_Pizzaria_e_Sanduicheria_Nova_Betania', 'parada_West_Flat', 'parada_UNP_Ida', 'parada_Maxxi_Atacado', 'parada_Avenida_Joao_da_Escossia_Ida0', 'parada_Splendore_Residence_Ida', 'parada_Avenida_Mota_Neto_Ida6', 'parada_Granero_Transportes', 'parada_Rede_Maquinas_Lateral', 'parada_Rua_Ricardo_Lima_Ida1', 'parada_Rua_Raimundo_Nonato_Chaves_Ida0', 'parada_Rua_Raimundo_Nonato_Chaves_Ida1', 'parada_Cantina_azul', 'parada_BR_405_Ida1', 'parada_Assembleia_de_Deus_Centenario_I', 'parada_Intensefit_Academia_Aeroporto', 'parada_Loja_Maconica_Uniao_Mossoroense', 'parada_Rua_Anderson_Dutra_Volta0', 'parada_Rua_Felipe_Camarao_Ida0', 'parada_Posto_Ipiranga_Aeroporto_Ida', 'parada_Posto_Ipiranga_Aeroporto_Volta', 'parada_HRTM', 'parada_Rua_Ricardo_Guilherme_de_Lima_Volta0', 'parada_Capela_Santo_Expedito_Aeroporto', 'parada_Avenida_Mota_Neto_Ida0', 'parada_ICPI', 'parada_UBS_Chico_Porto', 'parada_Avenida_Mota_Neto_Ida2', 'parada_Avenida_Mota_Neto_Ida3', 'parada_Spazio_di_Leone', 'parada_Avenida_Mota_Neto_Ida4', 'parada_Avenida_Mota_Neto_Ida5', 'parada_Igreja_Batista_Regular_Central', 'parada_Nossa_Corretora_de_Seguros'], ['parada_Nossa_Corretora_de_Seguros', 'parada_Rua_Delfim_Moreira_Volta0', 'parada_Rua_Venceslau_Braz_Volta0', 'parada_Rua_Venceslau_Braz_Ida0', 'parada_Rua_Joao_Cordeiro_Volta0', 'parada_Rua_Joao_Cordeiro_Volta1', 'parada_Avenida_Alberto_Maranhao_Norte_Volta0', 'parada_Igreja_Universal_do_Reino_de_Deus_Barrocas_Ida', 'parada_Avenida_Alberto_Maranhao_Norte_Ida0', 'parada_Rua_Zeca_Cirilino_Volta0', 'parada_Rua_Melo_Franco_Ida0', 'parada_Rua_Zeca_Cirilino_Ida1', 'parada_Rua_Zeca_Cirilino_Ida0', 'parada_Rua_Tabeliao_Aoem_Menescal_Ida0', 'parada_Rua_Jose_Dutra_de_Souza_Ida0', 'parada_Rua_Jeronimo_Rosado_de_Souza_Ida0', 'parada_Ida_Linha3', 'parada_Avenida_Rio_Branco_Norte_Ida0', 'parada_Posto_Fan_Santo_Antonio_Ida', 'parada_Posto_Fan_Santo_Antonio_Volta', 'parada_UBS_Joaquim_Saldanha_Ida', 'parada_EM_Raimunda_Nogueira_do_Couto_Ida', 'parada_Rua_Seis_de_Janeiro_Ida0', 'parada_Rua_Seis_de_Janeiro_Ida1', 'parada_Primeira_Igreja_Metodista_Wesleyana_Ida', 'parada_Rua_Seis_de_Janeiro_Volta0', 'parada_UPA_Conchecita_Ciarlini_Ida', 'parada_Rua_Melo_Franco_Ida1', 'parada_Rua_Melo_Franco_Volta0', 'parada_Rua_Orlando_Dantas_Volta0', 'parada_Rua_Orlando_Dantas_Volta1', 'parada_Rua_Vivaldo_Dantas_de_Farias_Ida0', 'parada_Rua_Joao_Cordeiro_Ida0', 'parada_Rua_Joao_Cordeiro_Ida1', 'parada_Nossa_Corretora_de_Seguros'], ['parada_Nossa_Corretora_de_Seguros', 'parada_UERN_Nucleo_de_Pratica_Juridica', 'parada_Praca_da_Convivencia', 'parada_Praca_do_Patins_Sadraque_Tavares', 'parada_Praca_dos_Esportes', 'parada_EM_Professor_Manoel_Assis', 'parada_Instituto_Aquarela', 'parada_Rua_Nisia_Floresta_Ida0', 'parada_EE_Onzieme_Rosado_Fernandes', 'parada_Praca_Raimundo_Rubira_Ida', 'parada_Rua_Silva_Jardim_Ida1', 'parada_Rua_Silva_Jardim_Ida0', 'parada_Assembleia_de_Deus_Boa_Vista_I', 'parada_Rua_Coelho_Neto_Ida0', 'parada_Aplastec_Center_Ida', 'parada_FUNDAC_Ida', 'parada_Rua_Francisco_Solon_Ida0', 'parada_Tiinha_Restaurante_Ida', 'parada_Rua_Francisco_Romualdo_Ida0', 'parada_Aeroporto', 'parada_Procon_Municipal_de_Mossoro_Ida', 'parada_SP_Combustiveis_Centro', 'parada_Avenida_Diocesana_Ida0', 'parada_Igreja_Sao_Joao_Ida', 'parada_Rua_Silva_Jardim_Volta0', 'parada_Wi_Fitness', 'parada_Rua_Frei_Miguelinho_Volta0', 'parada_Rua_Frei_Miguelinho_Volta1', 'parada_Jucas_Bar_e_Restaurante', 'parada_Rua_Frei_Miguelinho_Volta2', 'parada_Avenida_Diocesana_Volta0', 'parada_Avenida_Joao_da_Escossia_Ida2', 'parada_Cemiterio_Sao_Sebastiao_Lateral_Ida', 'parada_Nossa_Corretora_de_Seguros'], ['parada_Nossa_Corretora_de_Seguros', 'parada_UNP_Volta', 'parada_Sun_Ville', 'parada_Partage_Shopping', 'parada_UNINASSAU', 'parada_Posto_Shell_Posto_Olinda_Ltda', 'parada_Vnz_Jeep', 'parada_Rodoviaria_Detran_RN', 'parada_Posto_Real', 'parada_Rua_Francisca_da_Nobrega_Gurjel_Volta0', 'parada_Rua_Francisca_da_Nobrega_Gurjel_Volta1', 'parada_Rua_Francisca_da_Nobrega_Gurjel_Volta2', 'parada_Rua_Francisca_da_Nobrega_Gurjel_Volta3', 'parada_Rua_Francisca_da_Nobrega_Gurjel_Volta4', 'parada_Rua_Francisca_da_Nobrega_Gurjel_Volta5', 'parada_BR_405_Ida0', 'parada_Rua_Ricardo_Guilherme_de_Lima_Volta1', 'parada_Rua_Ricardo_Lima_Ida0', 'parada_Avenida_Mota_Neto_Ida1', 'parada_Rua_Gilberto_Mercelino_Sobrinho_Volta0', 'parada_Rua_Candido_Clementino_Barros_Ida0', 'parada_Igreja_Assembleia_de_Deus_Avivamento_e_Milagres', 'parada_Rua_Dolores_do_Carmo_Reboucas_Ida4', 'parada_Rua_Dolores_do_Carmo_Reboucas_Ida3', 'parada_Rua_Dolores_do_Carmo_Reboucas_Ida2', 'parada_Rua_Dolores_do_Carmo_Reboucas_Volta0', 'parada_Rua_Dolores_do_Carmo_Reboucas_Ida0', 'parada_Residencial_Celina_Guimaraes_Lateral_Volta0', 'parada_Residencial_Celina_Guimaraes_Lateral_Ida0', 'parada_Residencial_Celina_Guimaraes', 'parada_Nossa_Corretora_de_Seguros'], ['parada_Nossa_Corretora_de_Seguros', 'parada_Avenida_Joao_da_Escossia_Volta0', 'parada_EE_Professor_Eliseu_Viana_Ida', 'parada_CEM_Ida', 'parada_Colegio_Diocesano_Santa_Luzia_Ida', 'parada_ADVM', 'parada_EE_Jeronimo_Rosado_Ida', 'parada_Olinda_Pneus_Santo_Antonio_Volta', 'parada_Olinda_Pneus_Santo_Antonio_Ida', 'parada_Mater_Christi', 'parada_Farmacia_do_Trabalhador_Santo_Antonio', 'parada_Rua_Campos_Sales_Ida0', 'parada_Rua_Monsenhor_Gurgel0', 'parada_EM_Monsenhor_Mota', 'parada_Rua_Monsenhor_Gurgel1', 'parada_Igreja_de_Nossa_Senhora_de_Fatima_Abolicao_Volta', 'parada_Avenida_Abel_Coelho_Volta0', 'parada_Avenida_Abel_Coelho_Volta1', 'parada_Avenida_Abel_Coelho_Ida0', 'parada_Avenida_Abel_Coelho_Ida1', 'parada_Igreja_de_Nossa_Senhora_de_Fatima_Abolicao_Ida', 'parada_Rua_Doutor_Joao_Marcelino_Ida0', 'parada_Rua_Doutor_Joao_Marcelino_Ida1', 'parada_EE_Doutor_Lavoisier_Maia_Ida', 'parada_EE_Professor_Abel_Freire_Coelho_Ida', 'parada_SESC_Ida', 'parada_Nogueirao_Volta', 'parada_Avenida_Joao_da_Escossia_Ida1', 'parada_Nogueirao_Ida', 'parada_Nossa_Corretora_de_Seguros'], ['parada_Nossa_Corretora_de_Seguros', 'parada_Loterica_Sorteca', 'parada_Igreja_Sao_Vicente', 'parada_Shopping_Boulevard', 'parada_Lojas_Americanas_Centro', 'terminal_Carcara', 'parada_O_Sebosao', 'parada_Arte_da_Terra', 'parada_Livraria_Independencia', 'parada_CIEE', 'parada_Hotel_Caraubas', 'parada_Rua_Doutor_Mario_Negocio0', 'parada_Praca_Antonio_Gomes', 'parada_FMA_Imobiliaria', 'parada_Catedral_de_Santa_Luzia', 'parada_Igreja_Universal_do_Reino_de_Deus_Centro', 'parada_Cobal', 'parada_Rua_Marechal_Deodoro_Volta0', 'parada_Lateral_Quadra_de_Esportes_CPP_Volta', 'parada_Rua_Venceslau_Braz_Ida2', 'parada_Rua_Prudente_de_Morais0', 'parada_Cirne_Pneus_Mossoro', 'parada_Reboucas_Supermercados_Centro', 'parada_Rua_Ferreira_Itajuba_Ida0', 'parada_Praca_dos_Hospitais', 'parada_Praca_de_Eventos_Ida', 'parada_Rua_Doutor_Joao_Marcelino_Volta0', 'parada_Estacao_das_Artes', 'parada_Cemiterio_Sao_Sebastiao', 'parada_Supermercado_Cidade_Alternativo_Ida', 'parada_Nossa_Corretora_de_Seguros']]]

    # generate_maps(inst=inst, major_hub=final_major_hub, hubs=final_hubs, cycles=final_cycles,
    #               filename=f'{map_path}/optimized_solution')

    feeder_trunk_paths: list[list[str]] = [[final_cycles[0][0][0], final_major_hub, final_cycles[2][0][0]],
                                           [final_cycles[1][0][0], final_major_hub, final_cycles[3][0][0]]]
    hub_and_spoke_paths: list[list[str]] = [[cluster[0][0], final_major_hub] for cluster in final_cycles]
    gtfs_path: str = f'outputs/gtfs/gtfs_{random_state}'
    Path(f'{gtfs_path}/ft').mkdir(parents=True, exist_ok=True)
    Path(f'{gtfs_path}/hs').mkdir(parents=True, exist_ok=True)
    print('FT')
    generate_gtfs(inst=inst, paths=feeder_trunk_paths, cycles=final_cycles, out_dir=f'{gtfs_path}/ft')
    print('HS')
    generate_gtfs(inst=inst, paths=hub_and_spoke_paths, cycles=final_cycles, out_dir=f'{gtfs_path}/hs')

    end_time: float = time.process_time()

    Path('outputs/costs').mkdir(parents=True, exist_ok=True)
    with open(file=f'outputs/costs/costs_{random_state}.txt', mode='w') as file:
        initial_cycle_costs: list[list[int]]
        initial_cluster_costs: list[int]
        initial_overall_cost: int
        initial_cycle_costs, initial_cluster_costs, initial_overall_cost = calculate_costs(inst=inst,
                                                                                           major_hub=initial_major_hub,
                                                                                           cycles=initial_cycles)
        final_cycle_costs: list[list[int]]
        final_cluster_costs: list[int]
        final_overall_cost: int
        final_cycle_costs, final_cluster_costs, final_overall_cost = calculate_costs(inst=inst,
                                                                                     major_hub=final_major_hub,
                                                                                     cycles=final_cycles)

        costs: str = ''

        costs += 'Custos iniciais\n'
        costs += f'Custos por ciclo: {initial_cycle_costs}\n'
        costs += f'Custos por cluster: {initial_cluster_costs}\n'
        costs += f'Custo geral: {initial_overall_cost}\n\n'

        costs += 'Custos finais\n'
        costs += f'Custos por ciclo: {final_cycle_costs}\n'
        costs += f'Custos por cluster: {final_cluster_costs}\n'
        costs += f'Custo geral: {final_overall_cost}\n\n'

        cost_diff: float
        for i in range(len(final_cluster_costs)):
            cost_diff = ((final_cluster_costs[i] - initial_cluster_costs[i]) / initial_cluster_costs[i]) * 100
            costs += f'Porcentagem de otimização do cluster {i}: {cost_diff:.2f} %\n'
        cost_diff = ((final_overall_cost - initial_overall_cost) / initial_overall_cost) * 100
        costs += f'Porcentagem de otimização geral: {cost_diff:.2f} %\n\n'

        time_diff: int = int(end_time - start_time)
        costs += f'Tempo de execução: {time_diff} segundos\n'

        pd.DataFrame({'Custo inicial': [initial_overall_cost], 'Custo final': [final_overall_cost],
                      'Diferença de custo (%)': [f'{cost_diff:.2f}'],
                      'Tempo de execução (segundos)': [time_diff]}).to_csv(
            path_or_buf=f'outputs/costs/cost_{random_state}.csv', index=False)
        file.write(costs)

    Path('outputs/solutions').mkdir(parents=True, exist_ok=True)
    with open(file=f'outputs/solutions/solutions_{random_state}.txt', mode='w') as file:
        solutions: str = ''

        solutions += f'Grande hub: {final_major_hub}\n\n'
        solutions += f'Hubs: {final_hubs}\n\n'
        solutions += f'Ciclos: {final_cycles}\n'

        file.write(solutions)


if __name__ == '__main__':
    main(random_state=3)
    # for curr_random_state in range(10):
    #     main(random_state=curr_random_state)
    # main(random_state=42)
