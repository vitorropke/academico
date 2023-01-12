# somador completo
def meio_somador_de_1_bit(a, b):
	# a ^ b	XOR	Soma
	# a & b	AND	Carry Out
	return a ^ b, a & b

def somador_completo(a, b, carry_in):
	soma_inicial, carry_out_inicial = meio_somador_de_1_bit(a, b)

	soma_final, carry_out_central = meio_somador_de_1_bit(carry_in, soma_inicial)

	# carry_out_inicial | carry_out_central	OR
	return soma_final, carry_out_inicial | carry_out_central

a = int(input("\nDigite o valor para A: "))
b = int(input("Digite o valor para B: "))
carry_in = int(input("Digite o valor para Carry In: "))

soma, carry_out = somador_completo(a, b, carry_in)

print("\nSoma:\t\t", soma)
print("Carry Out:\t", carry_out, '\n')
