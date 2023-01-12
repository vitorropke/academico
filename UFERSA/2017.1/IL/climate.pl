%Factos
clima(mossoro, quente, verao).
clima(mossoro, quente, inverno).
clima(natal, quente, verao).
clima(natal, frio, inverno).
clima(curitiba, frio, inverno).
clima(curitiba, frio, verao).
clima(gramado, frio, inverno).
clima(gramado, quente, verao).

%Regeas
maisquente(X, Y):-clima(X, quente, inverno), clima(Y, frio, inverno).
maisfrio(X, Y):-clima(X, frio, verao), clima(Y, frio, inverno).

quente(X):-clima(X, quente, inverno).
frio(X):-clima(X, frio, verao).
