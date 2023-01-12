# expressão que calcula os erros absoluto, relativo e percentual

numero_racional = float(input("\nDigite um numero racional: "))
numero_arredondado = float(input("Digite esse numero, arredondado: "))

erro_absoluto = numero_racional - numero_arredondado
erro_relativo = erro_absoluto / numero_racional
erro_percentual = erro_relativo * 100

print("\nErro absoluto:\t {:.3f}".format(erro_absoluto))
print("Erro relativo:\t {:.3f}".format(erro_relativo))
print("Erro percentual: {:.3f}%\n".format(erro_percentual))
