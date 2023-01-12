def ext_dezena(num):
    unidade=["zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"]
    dez=["dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"]
    dezena=["zero", "dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"]
    tamanho=len(num)
    if int(num[tamanho-2])==0 or tamanho==1:
        return unidade[int(num[tamanho-1])]
    elif int(num[tamanho-1])==0:
        return dezena[int(num[tamanho-2])]
    elif int(num[tamanho-2])==1:
        return dez[int(num[tamanho-1])]
    else:
        return dezena[int(num[tamanho-2])]+ " e " +unidade[int(num[tamanho-1])]

def ext_centena(num):
    tamanho=len(num)
    centena=["zero", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos", ]
    if tamanho>2 and int(num[tamanho-3])>0:
        return centena[int(num[tamanho-3])]+ " e " +ext_dezena(num[tamanho-2:tamanho])
    else:
        return ext_dezena(num)

num=input("Digite um número: ")
tamanho=len(num)
if tamanho>3 and int(num[tamanho-3])>0 and int(num[tamanho-4])==1:
    print("mil", ext_centena(num[tamanho-3:tamanho]))
elif tamanho>3 and int(num[tamanho-3])>0:
    print(ext_centena(num[0:tamanho-3]), "mil", ext_centena(num[tamanho-3:tamanho]))
elif tamanho>3 and int(num[0:tamanho-3])>0:
    print(ext_centena(num[0:tamanho-3]), "mil e", ext_centena(num[tamanho-3:tamanho]))
else:
    print(ext_centena(num))
