
# Compiladores
CC=g++
LEX=flex++

# Dependências
all: html

html: lex.yy.cc
	$(CC) lex.yy.cc -std=c++17 -o html

lex.yy.cc: html.l
	$(LEX) html.l

clean:
	rm html lex.yy.cc
