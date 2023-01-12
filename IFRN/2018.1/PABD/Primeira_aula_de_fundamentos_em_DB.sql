#Um comentário qualquer
CREATE DATABASE loja;

USE loja;

CREATE TABLE produtos(
id INT AUTO_INCREMENT PRIMARY KEY,
nome VARCHAR(100) NOT NULL,
estoque FLOAT DEFAULT 0,
preco FLOAT);

INSERT INTO produtos VALUES
(1, "Coxinha", 6, 1.50);

INSERT INTO produtos VALUES
(NULL, "Pastel", 8, 2.00);

INSERT INTO produtos (nome, preco)
VALUES ("Coca-cola lata", 2.50);

INSERT INTO produtos (nome)
VALUES ("Fandangos");

INSERT INTO produtos VALUES
(NULL, "Bombom", 10, 2.00),
(NULL, "Cheetos", 15, 2.99),
(NULL, "Caixa de chocolate Nestlé 300g", 10, 4.20),
(NULL, "Nutella 500g", 4, 99.00),
(NULL, "Ovo da páscoa 500g", 90, 50.99),
(NULL, "Fini", 6, 2.00);

SELECT * FROM produtos;

SELECT * FROM produtos
ORDER BY nome;

SELECT * FROM produtos
ORDER BY preco DESC;

SELECT * FROM produtos
WHERE preco <= 2;

SELECT * FROM produtos
WHERE estoque > 5
ORDER BY estoque;

UPDATE produtos
SET preco = 4.50
WHERE id = 4;

UPDATE produtos
SET preco = preco * 1.10;

UPDATE produtos
SET preco = 2
WHERE preco >= 2.2
AND preco <=2.3;

UPDATE produtos
SET estoque = 30,
preco = 1.5
WHERE id = 3;

DELETE FROM produtos
WHERE id = 10;