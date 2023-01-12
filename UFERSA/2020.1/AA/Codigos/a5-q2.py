def algoritmo(n):
	if(n == 0):
		return 1
	else:
		return algoritmo(n-1) + algoritmo(n-1)

print(algoritmo(3))