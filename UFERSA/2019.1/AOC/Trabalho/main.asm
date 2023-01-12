#Vitor Oliveira Ropke
#Programa principal que interage com o usuário. Faz o que o usuário manda.

.data
	menu:		.asciiz	"Digite o que o programa deve fazer\n0 para sair\n1 para contar os caracteres\n2 para comparar duas strings e informar a discrepância do tamanho entre as duas\n3 para juntar duas strings\n4 para juntar n caracteres da última string na primeira\n5 para copiar n caracteres da segunda string para a primeira\n"
	string1:	.asciiz	"Olá "	#Mensagem
	string2:	.asciiz "Mundo"	#Mensagem
.text
	addiu	$s1, $zero, 1	#'s1' recebe 1
	addiu	$s2, $zero, 2	#'s2' recebe 2
	addiu	$s3, $zero, 3	#'s3' recebe 3
	addiu	$s4, $zero, 4	#'s4' recebe 4
	addiu	$s5, $zero, 5	#'s5' recebe 5
	
	programa:	la	$a0, menu		#a0 recebe o endereço de 'menu' para posteriormente ser impresso
			li	$v0, 4			#v0 recebe o código 4 para imprimir
			syscall				#Chamada de sistema para imprimir
			
			li	$v0, 5			#Recebe um número inteiro do usuário
			syscall				#Chamada de sistema para receber número inteiro
			add	$s0, $v0, $zero		#Salvar o número digitado em 's0'
			
			la	$a0, string1		#Salva a string1 no primeiro argumento
			addi	$sp, $sp, -4		#Adiciona 1 espaço na pilha
			sw	$a0, 0($sp)		#Armazena a string1 na pilha para ser usada em algumas funções
			la	$a1, string1		#Salva a string2 no segundo argumento
			li	$a2, 4			#'a2' recebe 4
			
			beq	$s0, $zero, saida	#Se a entrada for 0, sair do programa
			beq	$s0, $s1, strlen	#se a entrada for 1, vá para a função strlen
			beq	$s0, $s2, strcmp	#se a entrada for 2, vá para a função strcmp
			beq	$s0, $s3, strcat	#se a entrada for 3, vá para a primeira strcat
			beq	$s0, $s4, strncat	#se a entrada for 4, vá para a primeira strncat
			beq	$s0, $s5, strncpy	#se a entrada for 5, vá para a primeira strncpy
			
			j	programa
	
	saida:	li	$v0, 10		#v0 recebe o código 10 para fechar o programa
		syscall			#Chamada de sistema para fechar o programa

.include "string.asm"
