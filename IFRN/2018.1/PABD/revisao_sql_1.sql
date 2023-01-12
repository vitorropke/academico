# criar o banco de dados
CREATE DATABASE loja;

# usar o banco
USE loja;

# criar tabela
CREATE TABLE produto(
id INT AUTO_INCREMENT PRIMARY KEY,
nome VARCHAR(100) NOT NULL,
estoque FLOAT DEFAULT 0,
preco FLOAT );

# inserir dados na tabela
INSERT INTO produto VALUES
(1, "Coxinha", 6, 1.50);

# sem fornecer o id
INSERT INTO produto VALUES
(NULL, "Pastel", 8, 2.00);

#fornecer apenas alguns dados
INSERT INTO produto (nome, preco)
VALUES ("Coca-cola lata", 2.50);

INSERT INTO produto (nome)
VALUES ("Fandangos");

# selecionar todos os dados
SELECT * FROM produto;

# ordem crescente (nome)   #ASC
SELECT * FROM produto 
ORDER BY nome;

# ordem decrescente
SELECT * FROM produto
ORDER BY preco DESC;

# ordenar por varias colunas
# ORDER BY estado, cidade, bairro

# incluindo condições
# ex. produtos que custam até 2,00
SELECT * FROM produto
WHERE preco <= 2;

SELECT * FROM produto
WHERE estoque > 5
ORDER BY estoque;

# alterar uma informação
UPDATE produto
SET preco = 4.50
WHERE id = 4;

#aumentar 10% em todos
UPDATE produto
SET preco = preco * 1.10;

UPDATE produto
SET preco = 2
WHERE preco >= 1.9
AND preco <= 2;

UPDATE produto
SET estoque = 30,
preco = 1.5 
WHERE id = 8;

#excluir um registro
DELETE FROM produto
WHERE id = 5;
