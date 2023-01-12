#! /bin/bash

find /home/aluno/ -mtime +60 -exec rm {} \;
#Comando find que significa encontrar.
#Após o find existe o diretório que se deseja varrer.
#-mtime é o tempo que foi passado em dias. No caso foram 60 dias. 2 Meses.
#-exec rm {} é o comando para deletar tais arquivos.
