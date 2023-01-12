class Aluno:
    nome = ""
    n1 = 0.0
    n2 = 0.0

    def media(self, n1, n2):
        self.mediaAritmetica = (n1 + n2) / 2
        return self.mediaAritmetica

aluno1 = Aluno()
aluno2 = Aluno()

aluno1.nome = input("Digite o nome do aluno 1: ")
aluno1.n1 = float(input("Digite a primeira nota do aluno 1: "))
aluno1.n2 = float(input("Digite a segunda nota do aluno 1: "))

print()
aluno2.nome = input("Digite o nome do aluno 2: ")
aluno2.n1 = float(input("Digite a primeira nota do aluno 2: "))
aluno2.n2 = float(input("Digite a segunda nota do aluno 2: "))

print()
print("Nome do aluno 1: ", aluno1.nome)
print("Média do aluno 1: ", aluno1.media(aluno1.n1, aluno1.n2))

print()
print("Nome do aluno 2: ", aluno2.nome)
print("Média do aluno 2: ", aluno2.media(aluno2.n1, aluno2.n2))
