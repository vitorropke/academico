%Questão 1
q1:-read(Nome), nl,
    write('Seja bem vindo'),
    write(Nome).

%Questão 2
q2:-read(N1), nl, read(N2),
    Soma is N1+N2,
    Subtracao is N1-N2, nl,
    write('Soma:'), write(Soma),
    write('Subtracao:'), nl, write(Subtracao).

%outra forma...
q2(N1, N2, Som, Sub):-Som is N1+N2, Sub is N1-N2.

%Questão 3
q3:-read(N), nl, Suc is N+1, Ant is N-1,
    write('Sucessor:'), write(Suc), nl,
    write('Antecessor:'), write(Ant), nl.

%outra forma...
q3(N, S, A):-S is N+1, A is N-1.

%Questão 5
q5:-read(N1), read(N2), read(N3),
    M is ((N1*2)+(N2*3)+(N3*4))/9, nl,
    write('Média:'), write(M).

%outra forma
q5(N1, N2, N3, M):-M is ((N1*2)+(N2*3)+(N3*4))/9.
