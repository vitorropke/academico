v1=int(input("Digite um valor: "))
v2=int(input("Digite um valor: "))

if (v1>v2):
	a=v1
	v1=v2
	v2=a

soma=0

print('Números do intervalo: ',end=' ')
for x in range(v1,v2+1):
	print(x,end=' ')
	soma=soma+x
	
print('Valores somados são iguais a {}'.format(soma))
