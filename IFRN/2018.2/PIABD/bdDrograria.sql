CREATE DATABASE bddrograria
USE bddrograria;

CREATE TABLE cliente (
rg VARCHAR(20) NOT NULL,
nome_cliente VARCHAR(50) NOT NULL,
cidade_reside VARCHAR(50) NOT NULL,
cidade_trabalha VARCHAR(50) NOT NULL,
data_nascimento DATE NULL,
PRIMARY KEY (rg)
);

CREATE TABLE compra (
nome_cliente VARCHAR(50) NOT NULL,
nome_funcionario VARCHAR(50) NOT NULL,
codigo_prod VARCHAR(50) NOT NULL
);

CREATE TABLE drogaria (
nome_drogaria VARCHAR(50) NOT NULL,
cidade VARCHAR(50) NOT NULL,
nome_funcionario VARCHAR(50) NOT NULL
);

CREATE TABLE funcionario (
rg VARCHAR(20) NOT NULL,
nome_funcionario VARCHAR(50) NOT NULL,
cidade_reside VARCHAR(50) NOT NULL,
cidade_trabalha VARCHAR(50) NOT NULL,
PRIMARY KEY (rg)
);

CREATE TABLE produto (
codigo_prod INT(11) NOT NULL AUTO_INCREMENT,
quantidade_estoque INT(11) NOT NULL,
PRIMARY KEY (codigo_prod)
);

INSERT  INTO cliente(rg,nome_cliente,cidade_reside,cidade_trabalha,data_nascimento) VALUES ('432.45.77.56','Zacarias','Apodi','Mossoro','0000-00-00');
INSERT  INTO funcionario(rg,nome_funcionario,cidade_reside,cidade_trabalha) VALUES ('123.456.789','Fulano de Souza','Mossoro','Natal');
INSERT  INTO produto(codigo_prod,quantidade_estoque) VALUES (54,2);

SELECT * FROM cliente;
SELECT nome_funcionario FROM funcionario WHERE cidade_reside = 'Mossoro';
SELECT * FROM produto WHERE quantidade_estoque < 10;