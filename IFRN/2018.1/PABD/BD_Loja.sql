CREATE DATABASE sistema;
USE sistema;
CREATE TABLE produto(
codigo INT PRIMARY KEY AUTO_INCREMENT,
nome VARCHAR(100) NOT NULL,
varejo BOOL,
atacado BOOL,
localv VARCHAR(100),
categoria VARCHAR(100),
preco FLOAT
);