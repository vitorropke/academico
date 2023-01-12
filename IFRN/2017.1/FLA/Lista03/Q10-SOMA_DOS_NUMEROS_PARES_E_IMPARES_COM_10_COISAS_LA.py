seq_i=0
seq_p=0

for i in range(10):
    x=int(input('Digite um valor: '))
    if (x%2==0):
        seq_p=seq_p+x
    else:
        seq_i=seq_i+x

print('Soma dos números pares é {}'.format(seq_p))
print('Soma dos números ímpares é {}'.format(seq_i))

if (seq_p>seq_i):
    print('A soma dos números ímpares ({}) são menores que os números pares ({})'.format(seq_i,seq_p))
elif (seq_p<seq_i):
    print('A soma dos números ímpares ({}) são maiores que os números pares ({})'.format(seq_i,seq_p))
else:
    print('A soma dos números pares ({}) e ímpares ({}) são iguais'.format(seq_p,seq_i))
