q1(N1,N2):-S is N1+N2,
           D is S mod 5,
           D==0->
           write('Divis�vel');
           write('N�o divis�vel').
