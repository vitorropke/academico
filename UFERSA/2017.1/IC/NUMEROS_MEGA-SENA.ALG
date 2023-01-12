Algoritmo "semnome"

Var
   aposta: vetor [0..6] de inteiro
   num, x: inteiro
   novo: caracter

Procedimento gerapalpite
Var
Inicio
   num <- randi(60)
Fimprocedimento

Procedimento imprimepalpite
Var
   y: inteiro
Inicio
   para y de 1 ate 6 faca
      escreva (aposta[y])
   fimpara
   escreval ()
Fimprocedimento

Inicio
   novo <- "s"
   repita
      escreva ("Este programa gera 6 números para você jogar na mega-sena: ")
      para x de 1 ate 6 faca
         gerapalpite
         aposta[x] <- num
      fimpara
      imprimepalpite
      escreval ("Tecla s para gerar um novo palpite: ")
      leia (novo)
   ate (novo <> "s")

Fimalgoritmo