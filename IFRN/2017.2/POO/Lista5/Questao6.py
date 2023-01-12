class Calculadora:
    resultadoUltimaOperacao = 0

    def Adicao(self, numero1, numero2):
        self.soma = numero1 + numero2
        self.resultadoUltimaOperacao = self.soma
        return self.soma

    def Subtracao(self, numero1, numero2):
        self.diferenca = numero1 - numero2
        self.resultadoUltimaOperacao = self.diferenca
        return self.diferenca

    def Multiplicacao(self, numero1, numero2):
        self.produto = numero1 * numero2
        self.resultadoUltimaOperacao = self.produto
        return self.produto

    def Divisao(self, numero1, numero2):
        self.razao = numero1 / numero2
        self.resultadoUltimaOperacao = self.razao
        return self.razao


calculadora = Calculadora()
operacao = 1

while operacao >= 1 and operacao <= 4:
    numero1 = float(input("Digite o primeiro número da operação: "))
    numero2 = float(input("Digite o segundo número da operação: "))
    
    print()
    print("Digite 1 para somar. Digite 2 para subtrair. Digite 3 para multiplicar. Digite 4 para dividir.")
    print("Se for qualquer coisa diferente disso iremos sair imediatamente.")
    print("O resultado da última operação feita foi igual a ", calculadora.resultadoUltimaOperacao)
    
    print()
    operacao = int(input("Digite aí o que fazer com estes números que tu digitastes: "))
    print()

    if operacao == 1:
        print("Resultado = ", calculadora.Adicao(numero1, numero2))

    elif operacao == 2:
        print("Resultado = ", calculadora.Subtracao(numero1, numero2))

    elif operacao == 3:
        print("Resultado = ", calculadora.Multiplicacao(numero1, numero2))

    elif operacao == 4:
        print("Resultado = ", calculadora.Divisao(numero1, numero2))

    else:
        print("Não seguistes as regras")

    print()
   
print("Tchau")
