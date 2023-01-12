Algoritmo "semnome"
// Disciplina  :  [Linguagem e Lógica de Programação] 
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 19/08/2017
Var
// Seção de Declarações das variáveis 
media, n1, n2, n3, media_final, recuperacao:real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
escreva("Digite a sua primeira nota: ")
leia(n1)
escreva("Digite a sua segunda nota: ")
leia(n2)
escreva("Digite a sua terceira nota: ")
leia(n3)
media<-((n1*2)+(n2*3)+(n3*4))/9
escreval("Sua média é ",media)
se (media>=7) entao
   escreva("Tu estáis aprovado.")
fimse
se (media<3.5) entao
   escreva("Tu estáis reprovado.")
fimse
se ((media>=3.5) e (media<7)) entao
   escreval("Tu estáis em recuperação. Deves fazer a quarta prova")
   escreva("Digite sua nota da 4ªprova: ")
   leia(recuperacao)
   media_final<-((media*7)+(recuperacao*3))/10
   se (media_final>=7) entao
      escreva("Tu estáis aprovado com média ",media_final)
   fimse
   se (media_final<7) entao
      escreva("Tu estáis reprovado com média ",media_final)
   fimse
fimse
Fimalgoritmo