for x in range(1000, 3001):
    if ((x % 7 == 0) and not (x % 5 == 0)):
        print(x, end=', ')
