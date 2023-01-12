num_votantes=int(input("Digite o número de votantes: "))

candidato_1=0
candidato_2=0
candidato_3=0
branco=0
nulo=0

for x in range(num_votantes):
    votante=int(input("Em quem tu votas? "))
    if votante == 1:
        candidato_1+=1
    elif votante == 2:
        candidato_2+=1
    elif votante == 3:
        candidato_3+=1
    elif votante == 0:
        branco+=1
    else:
        nulo+=1

print("Candidato 1 teve ", candidato_1, " voto(s). Isto equivale a ", candidato_1/num_votantes*100, "% dos votos.")
print("Candidato 2 teve ", candidato_2, " voto(s). Isto equivale a ", candidato_2/num_votantes*100, "% dos votos.")
print("Candidato 3 teve ", candidato_3, " voto(s). Isto equivale a ", candidato_3/num_votantes*100, "% dos votos.")
print("Branco teve ", branco, " voto(s). Isto equivale a ", branco/num_votantes*100, "% dos votos.")
print("Nulo teve ", nulo, " voto(s). Isto equivale a ", nulo/num_votantes*100, "% dos votos.")
