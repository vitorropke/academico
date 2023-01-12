class Elevador:
    andarAtual = 0
    totalDeAndaresNoPredio = 9
    capacidadeDoElevador = 6
    pessoasNoElevador = 0

    def __init__(self, totalDeAndaresNoPredio, capacidadeDoElevador):
        self.totalDeAndaresNoPredio = totalDeAndaresNoPredio
        self.capacidadeDoElevador = capacidadeDoElevador

    def Entrar(self, numero):
        self.espacoDisponivel = self.capacidadeDoElevador - self.pessoasNoElevador
        if numero <= self.espacoDisponivel:
            self.pessoasNoElevador += numero
            return True
        else:
            return False

    def Sair(self, numero):
        if numero <= self.pessoasNoElevador:
            self.pessoasNoElevador -= numero
            return True
        else:
            return False

    def Subir(self, numero):
        self.numeroDeAndaresDisponivelParaSubir = self.totalDeAndaresNoPredio - self.andarAtual
        if numero <= self.numeroDeAndaresDisponivelParaSubir:
            self.andarAtual += numero

    def Descer(self, numero):
        if numero <= self.andarAtual:
            self.andarAtual -= numero

    def Deslocar(self, andarDeDestino):
        while self.andarAtual != andarDeDestino:
            if andarDeDestino > self.andarAtual:
                elevador.Subir(1)
            elif andarDeDestino < self.andarAtual:
                elevador.Descer(1)