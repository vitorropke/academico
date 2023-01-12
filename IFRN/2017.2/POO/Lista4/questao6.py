import questão5

def primo(num):
    divisores=0
    for x in range(1,num+1):
        if questão5.divisivel(num,x):
            divisores+=1
    if divisores<=2:
        return True
    else:
        return False
