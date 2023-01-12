pergunta='s'
valor_total=0
while pergunta=='s':
    codigo=int(input("Digite um código para encontrar a peça: "))
    quantidade=int(input("Digite a quantidade que tu desejas: "))

    if codigo==1:
        print("Escolhestes {} porca(s) de 2mm. Valor total é R${}".format(quantidade, 0.25*quantidade))
        valor_total+=0.25*quantidade
    elif codigo==2:
        print("Escolhestes {} porca(s) de 3mm. Valor total é R${}".format(quantidade, 0.4*quantidade))
        valor_total+=0.4*quantidade
    elif codigo==3:
        print("Escolhestes {} porca(s) de 4mm. Valor total é R${}".format(quantidade, 0.55*quantidade))
        valor_total+=0.55*quantidade
    elif codigo==4:
        print("Escolhestes {} porca(s) de 5mm. Valor total é R${}".format(quantidade, 0.65*quantidade))
        valor_total+=0.65*quantidade
    elif codigo==5:
        print("Escolhestes {} porca(s) de 10mm. Valor total é R${}".format(quantidade, 1.65*quantidade))
        valor_total+=1.65*quantidade
    elif codigo==6:
        print("Escolhestes {} parafuso(s) de 2mm. Valor total é R${}".format(quantidade, 0.5*quantidade))
        valor_total+=0.5*quantidade
    elif codigo==7:
        print("Escolhestes {} parafuso(s) de 3mm. Valor total é R${}".format(quantidade, 0.75*quantidade))
        valor_total+=0.75*quantidade
    elif codigo==8:
        print("Escolhestes {} parafuso(s) de 4mm. Valor total é R${}".format(quantidade, 0.8*quantidade))
        valor_total+=0.8*quantidade
    elif codigo==9:
        print("Escolhestes {} parafuso(s) de 5mm. Valor total é R${}".format(quantidade, 0.85*quantidade))
        valor_total+=0.85*quantidade
    elif codigo==10:
        print("Escolhestes {} parafuso(s) de 10mm. Valor total é R${}".format(quantidade, 1.75*quantidade))
        valor_total+=1.75*quantidade
    else:
        print("Código inválido.")
    pergunta=input("Desejas mais alguma coisa? s/n: ")

print("O valor total de todas as peças solicitadas é igual a R$", valor_total)
