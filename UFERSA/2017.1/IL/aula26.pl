q1(N1, N2, N3):-Media is (N1+N2+N3)/3,
                Media>=7 -> write('Aprovado');
                            write('Reprovado').

q2(X):-X == 0 -> write('Nulo');
       Verifica is X mod 2,
       Verifica == 0 -> write('Par');
                        write('ímpar').

q3(N1, N2, N3, Maior):-(N1==N2, N2==N3) -> write('Iguais');
                       (N1>N2, N1>N3) -> Maior is N1;
                       (N2>N1, N2>N3) -> Maior is N2;
                       (N3>N1, N3>N2) -> Maior is N3.

q4(Compra, Venda, Lucro):-(Compra =< 25) ->
                          Lucro is Compra*0.7, Venda is Compra+Lucro;
                          (Compra>25, Compra<50) ->
                          Lucro is Compra*0.5, Venda is Compra+Lucro;
                          (Compra>=50) ->
                          Lucro is Compra*0.3, Venda is Compra+Lucro.

q5(Sbruto, Sliquido):-(Sbruto =< 1500) ->
                      Sliquido is Sbruto-(Sbruto*0.07);
                      (Sbruto>1500, Sbruto =< 3000) ->
                      Sliquido is Sbruto-(Sbruto*0.12);
                      Sliquido is Sbruto-(Sbruto*0.24).

