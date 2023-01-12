# interpolação polinomial quadrática

def busca_binaria_aproximada(vetor, alvo):
    tamanho_do_vetor = len(vetor)

    # verifica se o alvo está além dos limites do vetor
    if (alvo < vetor[0][0]) or (alvo > vetor[tamanho_do_vetor - 1][0]):
        return None

    limite_maximo_vetor = tamanho_do_vetor
    limite_minimo_vetor = 0
    posicao_atual = int(limite_maximo_vetor / 2)

    # busca binária - divide o vetor ao meio a cada busca
    while (limite_maximo_vetor != limite_minimo_vetor) and (vetor[posicao_atual][0] != alvo):
        if alvo > vetor[posicao_atual][0]:
            limite_minimo_vetor = posicao_atual + 1
        else:
            limite_maximo_vetor = posicao_atual - 1

        posicao_atual = int((limite_maximo_vetor + limite_minimo_vetor) / 2)

    # se a posição alcançada não foi exatamente no alvo
    if vetor[posicao_atual][0] != alvo:
        # procura o número mais próximo do alvo considerando a parte decimal
        if ((posicao_atual + 1) != tamanho_do_vetor) and (
                (vetor[posicao_atual + 1][0] - alvo) <= (alvo - vetor[posicao_atual][0])):
            posicao_atual += 1
        elif ((posicao_atual - 1) != -1) and ((alvo - vetor[posicao_atual - 1][0]) < (vetor[posicao_atual][0] - alvo)):
            posicao_atual -= 1

    return posicao_atual


def tres_valores_mais_proximos(vetor, valor):
    tamanho_do_vetor = len(vetor)
    indice_valor = busca_binaria_aproximada(vetor, valor)

    if indice_valor is None:
        return None

    # se o valor encontrado estiver no fim do vetor, retorna os três últimos
    if indice_valor == (tamanho_do_vetor - 1):
        return [tamanho_do_vetor - 3, tamanho_do_vetor - 2, tamanho_do_vetor - 1]
    # se o valor encontrado estiver no início do vetor, retorna os três primeiros
    elif (indice_valor == 0) or (len(vetor) == 3):
        return [0, 1, 2]

    # calcula a diferença entre os 4 pontos mais próximos ao valor
    diferenca = [0 for x in range(4)]

    # pré anterior
    if (indice_valor - 2) >= 0:
        diferenca[0] = vetor[indice_valor][0] - vetor[indice_valor - 2][0]
    else:
        diferenca[0] = -1
    # anterior
    diferenca[1] = vetor[indice_valor][0] - vetor[indice_valor - 1][0]
    # posterior
    diferenca[2] = vetor[indice_valor + 1][0] - vetor[indice_valor][0]
    # pós posterior
    if (indice_valor + 2) < len(vetor):
        diferenca[3] = vetor[indice_valor + 2][0] - vetor[indice_valor][0]
    else:
        diferenca[3] = -1

    # escolhe os 2 valores mais próximos
    resultado = [0 for x in range(3)]
    resultado[0] = indice_valor

    # verifica os valores anterior e posterior
    if diferenca[1] < diferenca[2]:
        resultado[1] = indice_valor - 1

        # verifica os valores pré anterior e pós posterior
        if (diferenca[0] == -1) or (diferenca[0] > diferenca[2]):
            resultado[2] = indice_valor + 1
        else:
            resultado[2] = indice_valor - 2
    else:
        resultado[1] = indice_valor + 1

        # verifica os valores pré anterior e pós posterior
        if (diferenca[3] == -1) or (diferenca[3] > diferenca[1]):
            resultado[2] = indice_valor - 1
        else:
            resultado[2] = indice_valor + 2

    resultado.sort()

    return resultado


def eliminacao_gaussiana(matriz):
    # linha0 = linha0 / matriz[linha0][0]
    # linha1 = linha1 - matriz[linha1][0] * linha0
    # linha2 = linha2 - matriz[linha2][0] * linha0

    # linha1 = linha1 / matriz[linha1][1]
    # linha0 = linha0 - matriz[linha0][1] * linha1
    # linha2 = linha2 - matriz[linha1][1] * linha1

    # linha2 = linha2 / matriz[linha2][2]
    # linha0 = linha0 - matriz[linha0][2] * linha2
    # linha1 = linha1 - matriz[linha1][2] * linha2

    for i in range(3):
        for y in range(3, i - 1, -1):
            matriz[i][y] /= matriz[i][i]

        for x in range(3):
            if x != i:
                for y in range(3, i - 1, -1):
                    matriz[x][y] -= matriz[x][i] * matriz[i][y]

    return matriz[0][3], matriz[1][3], matriz[2][3]


while True:
    numero_de_pontos = int(input("\nDigite o numero de pontos: "))

    if numero_de_pontos < 2:
        print("Precisa ser 3 ou mais pontos!")
    else:
        break

pontos = [[0 for y in range(2)] for x in range(numero_de_pontos)]

# insere valores do usuário no vetor
for i in range(numero_de_pontos):
    pontos[i][0] = float(input(f"\nDigite o valor x no ponto {i}: "))
    pontos[i][1] = float(input(f"Digite o valor y no ponto {i}: "))

ponto_a_calcular = float(input(
    "\nDigite o valor x a ser calculado. O valor deve estar entre o menor e maior valor digitado na coordenada x: "))

pontos_proximos = tres_valores_mais_proximos(pontos, ponto_a_calcular)

matriz = [[0 for y in range(4)] for x in range(3)]

# preenche a matriz com a equação do segundo grau ax² + bx + c = y
for x in range(3):
    # ax²
    matriz[x][0] = pontos[pontos_proximos[x]][0] ** 2
    # bx
    matriz[x][1] = pontos[pontos_proximos[x]][0]
    # c
    matriz[x][2] = 1
    # y
    matriz[x][3] = pontos[pontos_proximos[x]][1]

resultado = eliminacao_gaussiana(matriz)

print(f"\na = {resultado[0]:.2f}\nb = {resultado[1]:.2f}\nc = {resultado[2]:.2f}")
print(
    f"\nValor de y quando x = {ponto_a_calcular} é {resultado[0] * ponto_a_calcular ** 2 + resultado[1] * ponto_a_calcular + resultado[2]:.2f}\n")
