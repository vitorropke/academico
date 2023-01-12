#Vitor Oliveira Ropke
#Fun��es para manipular as strings. 
#Strlen: Conta os caracteres
#Strcmp: diz se as strings s�o iguais
#Strcat: junta strings
#Strncat: junta um determinado n�mero de strings
#Strncpy: Copia n n�meros de uma vari�vel para outra
.text
	#Fun��o de contagem de tamanho
	strlen:	addi	$sp, $sp, -4		#Adiciona um espa�o na pilha
		sw	$s0, 0($sp)		#Salva o valor de 's0' na pilha
		add	$s0, $zero, $zero	#'s0' recebe 0. Ser� o contador de caracteres e �ndice do loop
		
		#while(entrada!=0)
		loopStrlen:	add	$t1, $a0, $s0		#Carrega o endere�o do �ndice's0' da string'a0' em 't1'
				lb	$t0, 0($t1)		#Carrega o valor da string na posi��o 'a0(entrada da string)' em 't0'
				beq	$t0, $zero, vazioStrlen	#Salte para 'vazioStrlen' se a string acabar(valor 0)
				addi	$s0, $s0, 1		#Incremento de 's0(n�mero de caracteres)' em 1 unidade
				j	loopStrlen		#Salta para 'loopStrlen'
		
		vazioStrlen:	add	$v0, $s0, $zero		#Valor de retorno recebe o n�mero de caracteres da string
				lw	$s0, 0($sp)		#Recupera o valor de 's0'
				addi	$sp, $sp, 4		#Tira um espa�o na pilha
				jr	$ra			#Retorno do c�digo
	
	#Fun��o de compara��o
	strcmp:	addi	$sp, $sp, -12		#Adiciona 3 espa�os na pilha
		sw	$s0, 0($sp)		#Armazena o valor de 's0' na pilha
		sw	$s1, 4($sp)		#Armazena o valor de 's1' na pilha
		sw	$ra, 8($sp)		#Armazena o valor de 'ra' na pilha
		
		jal	strlen			#Salte para a fun��o 'strlen'
		add	$s0, $v0, $zero		#Carrega o resultado do tamanho da string 1 em 's0'
		
		lw	$a0, 0($sp)		#Carrega o valor da string2 da pilha em a0
		addi	$sp, $sp, 4		#Tira 1 espa�o da pilha
		
		jal	strlen			#Salte para a fun��o 'strlen'
		add	$s1, $v0, $zero		#Carrega o resultado do tamanho da string 2 e 's1'
		
		sub	$s0, $s0, $s1		#Realiza a opera��o entre o tamanho das strings. Se <0 ent�o string1<string2. Se =0 ent�o string1=string2. Se >0 ent�o string1>string2
		add	$v0, $s0, $zero		#Resultado da opera��o anterior para 'v0'. Valor de retorno
		
		lw	$ra, 8($sp)		#Recupera o valor de 'ra'
		lw	$s1, 4($sp)		#Recupera o valor de 's1'
		lw	$s0, 0($sp)		#Recupera o valor de 's0'
		addi	$sp, $sp, 12		#Remove 3 espa�os da pilha
		jr	$ra			#Retorno do c�digo
	
	#Fun��o de concatena��o
	strcat:	addi	$sp, $sp, -12		#Adiciona 3 espa�os na pilha
		sw	$s0, 0($sp)		#Armazena o valor de 's0' na pilha
		sw	$s1, 4($sp)		#Armazena o valor de 's1' na pilha
		sw	$ra, 8($sp)		#Armazena o valor de 'ra' na pilha
		
		jal	strlen			#Salte para a fun��o 'strlen'
		add	$s1, $v0, $zero		#Carrega o resultado do tamanho da string 1 em 's1'
		
		add	$s0, $zero, $zero	#'s0' recebe zero. Ser� o �ndice do loop
	
		loopStrcat:	add	$t1, $s0, $a1			#Carrega o endere�o do �ndice's0' da string'a2' em 't1'
				lb	$t2, 0($t1)			#Carrega o valor da string1 't1' em 't2'
				beq	$t2, $zero, vazioStrcat		#Se o valor da string digitada for zero v� para 'vazioStrncpy'
				add	$t3, $s1, $a0			#Carrega o endere�o do �ndice's1' da string'a0' em 'a0'
				sb	$t2, 0($t3)			#Armazena o valor da string digitada't2' em 't3'
				addi	$s0, $s0, 1			#Incremento de 's0' em 1 unidade. �ndice aumenta
				addi	$s1, $s1, 1			#Incremento de 's1' em 1 unidade. �ndice aumenta
				j	loopStrcat			#Salta para 'loopStrcat'
	
		vazioStrcat:	lw	$ra, 8($sp)		#Recupera o valor de 'ra'
				lw	$s1, 4($sp)		#Recupera o valor de 's1'
				lw	$s0, 0($sp)		#Recupera o valor de 's0'
				addi	$sp, $sp, 12		#Remove 3 espa�os da pilha
				jr	$ra			#Retorno do c�digo
	
	#Fun��o de concatena��o de n n�meros
	strncat:	addi	$sp, $sp, -12		#Adiciona 3 espa�os na pilha
			sw	$s0, 0($sp)		#Armazena o valor de 's0' na pilha
			sw	$s1, 4($sp)		#Armazena o valor de 's1' na pilha
			sw	$ra, 8($sp)		#Armazena o valor de 'ra' na pilha
			
			jal	strlen			#Salte para a fun��o 'strlen'
			add	$s1, $v0, $zero		#Carrega o resultado do tamanho da string 1 em 's1'
			
			add	$s0, $zero, $zero	#'s0' recebe zero. Ser� o �ndice do loop
			
			loopStrncat:	beq	$s0, $a2, vazioStrncat		#Se o n�mero de caracteres concatenados's0' for igual ao n�mero fornecido pelo usu�rio'a2' v� para 'vazioStrncpy'
					add	$t1, $s0, $a1			#Carrega o endere�o do �ndice's0' da string'a2' em 't1'
					lb	$t2, 0($t1)			#Carrega o valor da string1 't1' em 't2'
					beq	$t2, $zero, vazioStrncat	#Se o valor da string digitada for zero v� para 'vazioStrncpy'
					add	$t3, $s1, $a0			#Carrega o endere�o do �ndice's1' da string'a0' em 'a0'
					sb	$t2, 0($t3)			#Armazena o valor da string digitada't2' em 't3'
					addi	$s0, $s0, 1			#Incremento de 's0' em 1 unidade. �ndice aumenta
					addi	$s1, $s1, 1			#Incremento de 's1' em 1 unidade. �ndice aumenta
					j	loopStrncat			#Salta para 'loopStrncat'
			
			vazioStrncat:	lw	$ra, 8($sp)		#Recupera o valor de 'ra'
					lw	$s1, 4($sp)		#Recupera o valor de 's1'
					lw	$s0, 0($sp)		#Recupera o valor de 's0'
					addi	$sp, $sp, 12		#Remove 3 espa�os da pilha
					jr	$ra			#Retorno do c�digo
	
	#Fun��o de c�pia de n caracteres
	strncpy:	addi	$sp, $sp, -4		#Adiciona 1 espa�o na pilha
			sw	$s0, 0($sp)		#Armazena o valor de 's0' na pilha
			add	$s0, $zero, $zero	#Atribui o valor 0 a 's0' que ser� o �ndice do loop
			
			loopStrncpy:	beq	$s0, $a2, vazioStrncpy		#Se o n�mero de caracteres copiados's0' for igual ao n�mero fornecido pelo usu�rio'a2' v� para 'vazioStrncpy'
					add	$t1, $s0, $a1			#Carrega o endere�o do �ndice's0' da string2 'a1' em 't1'
					lb	$t2, 0($t1)			#Carrega o valor da string2 't1' em 't2'
					beq	$t2, $zero, vazioStrncpy	#Se o valor da string digitada for zero v� para 'vazioStrncpy'
					add	$t3, $s0, $a0			#Carrega o endere�o do �ndice's0' da string1'a0' em 't3'
					sb	$t2, 0($t3)			#Armazena o valor da string1 't2' em 't3'
					addi	$s0, $s0, 1			#Incremento de 's0' em 1 unidade. �ndice aumenta
					j	loopStrncpy			#Salta para 'loopStrncpy'
			
			vazioStrncpy:	lw	$s0, 0($sp)			#Carrega o valor que s0 tinha
					addi	$sp, $sp, 4			#Tira 1 espa�o na pilha
					jr	$ra				#Retorno do c�digo
