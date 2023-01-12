a=int(input('Digite um número: '))
x = 1
while (x<=10):
    print('{}x{}={}; '.format(x, a, a*x), end='')
    x = x+1

print('')
print('')

print('Com FOR...')
for x in range(1, 11):
    print('{}x{}={}; '.format(x, a, a*x), end='')
