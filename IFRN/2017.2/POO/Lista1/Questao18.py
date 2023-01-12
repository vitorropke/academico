valor_venda=float(input("Digite o valor da venda: R$"))
codigo=int(input("Digite o código com a forma de pagamente que tu queres: "))

if codigo==1:
    print("Escolhestes pagar a vista. Recebestes um desconto de 10%. Valor final ficou R$", valor_venda*0.9)
elif codigo==2:
    print("Escolhestes pagar em 30 dias. Recebestes um desconto de 5%. Valor final ficou R$", valor_venda*0.95)
elif codigo==3:
    print("Escolhestes pagar em 60 dias. O preço é o mesmo. Valor final ficou R$", valor_venda)
elif codigo==4:
    print("Escolhestes pagar em 90 dias. Recebestes um acréscimo de 5%. Valor final ficou R$", valor_venda*1.05)
elif codigo==5:
    print("Escolhestes pagar no cartão de débito. Recebestes um desconto de 8%. Valor final ficou R$", valor_venda*0.92)
elif codigo==6:
    print("Escolhestes pagar no cartão de crédito. Recebestes um desconto de 7%. Valor final ficou R$", valor_venda*0.93)
else:
    print("Código inválido.")
