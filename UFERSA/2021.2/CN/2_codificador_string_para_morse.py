# conversor de string para morse
def caractere_para_morse(caractere):
	return {
		'A': ".-",
		'B': "-...",
		'C': "-.-.",
		'D': "-..",
		'E': ".",
		'F': "..-.",
		'G': "--.",
		'H': "....",
		'I': "..",
		'J': ".---",
		'K': "-.-",
		'L': ".-..",
		'M': "--",
		'N': "-.",
		'O': "---",
		'P': ".--.",
		'Q': "--.-",
		'R': ".-.",
		'S': "...",
		'T': "-",
		'U': "..-",
		'V': "...-",
		'W': ".--",
		'X': "-..-",
		'Y': "-.--",
		'Z': "--..",
		'0': "-----",
		'1': ".----",
		'2': "..---",
		'3': "...--",
		'4': "....-",
		'5': ".....",
		'6': "-....",
		'7': "--...",
		'8': "---..",
		'9': "----."
	}.get(caractere)

entrada = input("\nDigite o texto a ser codificado: ")
entrada = entrada.upper()

saida = ""

for caractere in entrada:
	if caractere == ' ':
		saida += "/ "
	else:
		saida += caractere_para_morse(caractere) + ' '

# remove o espaço que ficou no final
saida = saida[:-1]

print('\n', saida, '\n')
