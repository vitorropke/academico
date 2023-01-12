class Empregado:
    primeiroNome = ""
    sobrenome = ""
    salarioMensal = 0

    def __init__(self, primeiroNome, sobrenome, salarioMensal):
        self.primeiroNome = primeiroNome
        self.sobrenome = sobrenome
        self.salarioMensal = salarioMensal

    def aumento(self):
        self.salarioMensal += self.salarioMensal * 0.1
        return self.salarioMensal

class salarioAnual(Empregado):

    def remuneracaoAnual(self):
        self.pagamentoAnual = self.salarioMensal * 13 + self.salarioMensal * 1/3
        return self.pagamentoAnual

primeiroNome = input("Digite o primeiro nome do indivíduo: ")
sobrenome = input("Digite o sobrenome do indivíduo: ")
salarioMensal = float(input("Digite o salario mensal do individuo: "))
empregado1 = salarioAnual(primeiroNome, sobrenome, salarioMensal)

print()
primeiroNome = input("Digite o primeiro nome do indivíduo: ")
sobrenome = input("Digite o sobrenome do indivíduo: ")
salarioMensal = float(input("Digite o salario mensal do individuo: "))
empregado2 = salarioAnual(primeiroNome, sobrenome, salarioMensal)

print()
print("Nome completo: ", empregado1.primeiroNome, end = ' ')
print(empregado1.sobrenome)
print("Salario anual: %.2f" %empregado1.remuneracaoAnual())

print()
print("Nome completo: ", empregado2.primeiroNome, end = ' ')
print(empregado2.sobrenome)
print("Salario anual: %.2f" %empregado2.remuneracaoAnual())

empregado1.aumento()
empregado2.aumento()

print()
print("Nome completo: ", empregado1.primeiroNome, end = ' ')
print(empregado1.sobrenome)
print("Salario anual após aumento: %.2f" %empregado1.remuneracaoAnual())

print()
print("Nome completo: ", empregado2.primeiroNome, end = ' ')
print(empregado2.sobrenome)
print("Salario anual após aumento: %.2f" %empregado2.remuneracaoAnual())
