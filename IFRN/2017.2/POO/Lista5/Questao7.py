class Funcionario:
    nome = ""
    matricula = ""

class Engenheiro(Funcionario):
    setor = "Vendas"

    def identificar(setorAlvo):
        setor = "Vendas"
        if setor == setorAlvo:
            return True
        else:
            return False

    def operar(pc):
        print()
        print("Engenheiro {}, código {}, está operando o computador com uma memória de {}GB".format(Engenheiro.nome, Engenheiro.matricula, pc.memoria))
        print()
        pc.contar(100)
        pc.primo(123)

class Computador:
    memoria = 0

    def contar(numero):
        for x in range(numero + 1):
            print(x, end = ' ')

    def primo(numero):
        divisores = 0

        for x in range(1, numero + 1):
            if numero % x == 0:
                divisores += 1

        if divisores <= 2:
            return True
        else:
            return False

engenheiro = Engenheiro
computador = Computador

engenheiro.nome = input("Digite o nome do engenheiro: ")
engenheiro.matricula = input("Digite a matricula do engenheiro: ")
engenheiro.identificar.setorAlvo = input("Digite o setor do engenheiro: ")

computador.memoria = int(input("Digite quanto de memória tem este computador que o engenheiro está operando: "))

engenheiro.operar(computador)

print()
print()
if engenheiro.identificar(engenheiro.identificar.setorAlvo):
    print("Acertastes o setor do engenheiro")
else:
    print("Esse não é o setor do engenheiro")

print()
if computador.primo(123):
    print("123 é primo!")
else:
    print("123 não é primo!")