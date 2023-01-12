#Q1
CREATE TABLE Pessoa (
	nome VARCHAR(30) NOT NULL,
	cpf CHAR(11) NOT NULL PRIMARY KEY,
	endereco VARCHAR(100) NOT NULL,
	email VARCHAR(30),
	telefone VARCHAR(11)
);

CREATE TABLE Cliente () INHERITS (Pessoa);

CREATE TABLE Emprestavel (
	titulo VARCHAR(30) NOT NULL PRIMARY KEY,
	numeroExemplares INT,
	numeroEmprestimos INT,
	numeroDiasAlugado INT,
	anoLancamento INT,
	valorAluguel FLOAT
);

CREATE TABLE Livro (
	genero VARCHAR(20) NOT NULL,
	numeroPaginas INT NOT NULL
) INHERITS (Emprestavel);

CREATE TABLE Disco (
	banda VARCHAR(30) NOT NULL,
	estilo VARCHAR(20) NOT NULL
) INHERITS (Emprestavel);

CREATE TABLE Emprestimo (
	faturamento FLOAT,
	id BIGINT NOT NULL PRIMARY KEY,
	dataEmprestimo TIMESTAMP NOT NULL,
	idEmprestavel VARCHAR(30) REFERENCES Emprestavel(titulo) NOT NULL,
	dataDevolucaoEmprestavel TIMESTAMP NOT NULL,
	quantidadeEmprestavel INT NOT NULL
);

INSERT INTO Cliente(nome, cpf, email, endereco, telefone) VALUES
('Vitor', '17715819995', 'vitor@hotmail.com', 'Avenida Longe do Lugar, S/N', '8499999599');

INSERT INTO Livro(titulo, genero, numeroPaginas) VALUES
('Sem título válido', 'Comédia', 20);

INSERT INTO Emprestavel(titulo, numeroExemplares, numeroEmprestimos) VALUES
('Outro título', 20, 2);

INSERT INTO Emprestimo(id, dataEmprestimo, idEmprestavel, dataDevolucaoEmprestavel, quantidadeEmprestavel) VALUES
(1, '20210817 11:33:00 AM', 'Outro título', '20210830 11:58:12 AM', 2);


#Q2
CREATE TABLE Usuario (
	login VARCHAR(30) NOT NULL,
	senha VARCHAR(30) NOT NULL,
	PRIMARY KEY(cpf, login)
) INHERITS (Pessoa);


#Q3
CREATE TABLE Objeto (
	idEmprestavel VARCHAR(30) REFERENCES Emprestavel(titulo)
	ON DELETE CASCADE ON UPDATE CASCADE,
	dataDevolucaoEmprestavel TIMESTAMP NOT NULL,
	quantidadeEmprestavel INT NOT NULL
);


#Q4
ALTER TABLE Cliente ADD colunaTeste VARCHAR(20);


#Q5
UPDATE Cliente SET nome = 'Vitor Oliveira Ropke' WHERE nome = 'Vitor';


#Q6
ALTER TABLE Cliente RENAME COLUMN colunaTeste TO colunaTestada;


#Q7
ALTER TABLE Cliente DROP COLUMN colunaTestada;


#Q8
ALTER TABLE Pessoa ALTER COLUMN email TYPE VARCHAR(40);


#Q9
ALTER TABLE Objeto RENAME TO ObjetoEmprestavel;


#Q10
DROP TABLE ObjetoEmprestavel;


#Q11
ALTER TABLE Emprestimo ALTER COLUMN dataEmprestimo SET DEFAULT CURRENT_TIMESTAMP;


#Q12
ALTER TABLE Emprestimo ALTER COLUMN dataEmprestimo SET DEFAULT '20000101 00:00:00 AM';

#Q13
ALTER TABLE Emprestimo ADD CONSTRAINT dataDevolucaoEmprestavel 
CHECK (dataDevolucaoEmprestavel > CURRENT_TIMESTAMP);


#Q14
ALTER TABLE Emprestimo ADD CONSTRAINT dataDevolucaoEmprestavel 
CHECK (dataDevolucaoEmprestavel > CURRENT_TIMESTAMP AND quantidadeEmprestavel > 0);


#Q15
ALTER TABLE Emprestimo DROP CONSTRAINT dataDevolucaoEmprestavel;
ALTER TABLE Emprestimo ADD CONSTRAINT dataDevolucaoEmprestavel 
CHECK (dataDevolucaoEmprestavel > CURRENT_TIMESTAMP AND quantidadeEmprestavel > 1);


#Q16
ALTER TABLE Emprestimo DROP CONSTRAINT dataDevolucaoEmprestavel;


#Q17
UPDATE Emprestimo SET dataDevolucaoEmprestavel = '20211001 00:00:00 AM' WHERE id = 1;


#Q18
DELETE FROM Emprestimo WHERE id = 1;

#Q19
UPDATE Emprestavel SET titulo = 'novo titulo' WHERE titulo = 'Outro título';
DELETE FROM Emprestavel WHERE titulo = 'novo titulo';

#Q20
SELECT nome, telefone FROM Cliente;


#Q21
SELECT * FROM Emprestavel WHERE numeroExemplares >= 5;


#Q22
SELECT * FROM Emprestavel ORDER BY numeroExemplares;


#Q23
SELECT DISTINCT numeroPaginas FROM Livro;


#Q24
SELECT
	max(numeroPaginas) AS maiorNumeroPaginas,
	min(numeroPaginas) AS menorNumeroPaginas,
	avg(numeroPaginas) AS mediaNumeroPaginas,
	count(titulo) AS numeroLivros,
	sum(numeroPaginas) AS somaPaginasLivros
FROM Livro;


#Q25
SELECT * FROM Livro WHERE numeroPaginas BETWEEN 2 AND 30;
SELECT * FROM Livro WHERE numeroPaginas NOT BETWEEN 2 AND 30;

#Q26
SELECT * FROM Livro WHERE numeroPaginas IN (1200);
SELECT * FROM Livro WHERE numeroPaginas NOT IN (1200);


#Q27
SELECT titulo, numeroPaginas + 2 + EXP(40) AS valorAluguelExponencial FROM Livro;


#Q28
SELECT * FROM Livro WHERE titulo LIKE '%titulo%';
SELECT * FROM Livro WHERE titulo LIKE 'a ____ %';


#Q29
SELECT titulo, numeroExemplares, numeroPaginas FROM Livro
WHERE numeroExemplares > 3 AND numeroPaginas > 50;

SELECT titulo, numeroExemplares, numeroPaginas, valorAluguel FROM Livro
WHERE numeroExemplares < 5 OR valorAluguel > 50;


#Q30
SELECT titulo, numeroPaginas,
	CASE
		WHEN numeroPaginas > 200 THEN 'Livro gigantesco'
		ELSE 'Livro minúsculo'
	END
FROM Livro;


#Q31
	#a
	SELECT * FROM Disco CROSS JOIN Emprestavel;


	#b
	SELECT * FROM Disco INNER JOIN Livro USING (numeroExemplares);
	SELECT * FROM Disco LEFT JOIN Livro USING (numeroExemplares);
	SELECT * FROM Disco RIGHT JOIN Livro USING (numeroExemplares);


	#c
	SELECT idEmprestavel FROM Emprestimo UNION SELECT titulo FROM Livro;

	SELECT idEmprestavel FROM Emprestimo INTERSECT SELECT titulo FROM Livro;

	SELECT titulo FROM Livro EXCEPT SELECT idEmprestavel FROM Emprestimo;
	SELECT idEmprestavel FROM Emprestimo EXCEPT SELECT titulo FROM Livro;


	#d
	SELECT titulo, numeroExemplares FROM Emprestavel WHERE titulo 
	IN (SELECT titulo FROM Livro);
	SELECT titulo, numeroExemplares FROM Emprestavel WHERE titulo 
	NOT IN (SELECT titulo FROM Livro);


#Q32
CREATE TABLE Objeto (
	idEmprestavel VARCHAR(30) REFERENCES Emprestavel(titulo),
	dataEmprestimo DATE,
	horaEmprestimo TIME,
	dataDevolucao DATE,
	horaDevolucao TIME
);


#Q33
SELECT * FROM Objeto WHERE dataDevolucao > CURRENT_DATE;
SELECT * FROM Objeto WHERE horaEmprestimo <= '12:00:00' AND horaDevolucao <= '12:00:00';


#Q34
CREATE VIEW Precos AS (SELECT titulo, valorAluguel FROM Livro);


#Q35
SELECT titulo, valorAluguel FROM Precos;

UPDATE Precos SET valorAluguel = 15.7 WHERE titulo = 'novo Titulo';

INSERT INTO Precos VALUES
('O pequeno príncipe', 20);

CREATE TABLE Livro2 (
	titulo VARCHAR(30),
	genero VARCHAR(20),
	numeroPaginas INT,
	numeroExemplares INT,
	numeroEmprestimos INT,
	numeroDiasAlugado INT,
	anoLancamento INT,
	valorAluguel FLOAT
);
CREATE VIEW Precos2 AS (SELECT titulo, valorAluguel FROM Livro2);
INSERT INTO Precos2 VALUES
('O pequeno príncipe', 20);
SELECT * FROM Precos2;


#Q36
CREATE VIEW Aleatorios AS
(SELECT A.nome, A.telefone, B.titulo, B.valorAluguel
FROM Cliente AS A, Livro AS B);
