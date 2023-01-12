q1(N1,N2):-S is N1+N2,
           D is S mod 5,
           D==0->
           write('Divisível');
           write('Não divisível').
