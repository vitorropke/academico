CREATE DATABASE dbEscola;
USE dbEscola;
CREATE TABLE tbAlunos(
idAluno INT(4) AUTO_INCREMENT PRIMARY KEY NOT NULL,
nomeAluno VARCHAR(64) NOT NULL,
idadeAluno INT(2) NOT NULL,
enderecoAluno VARCHAR(64) NOT NULL,
telefoneAluno VARCHAR(15) NOT NULL,
emailAluno VARCHAR(64) NOT NULL
);

CREATE TABLE tbProfessores(
idProfessor INT(4) AUTO_INCREMENT PRIMARY KEY NOT NULL,
nomeProfessor VARCHAR(64) NOT NULL,
idadeProfessor INT(2) NOT NULL,
cpfProfessor VARCHAR(14) NOT NULL,
rgProfessor VARCHAR(20) NOT NULL,
enderecoProfessor VARCHAR(64) NOT NULL,
telefoneProfessor VARCHAR(15) NOT NULL,
emailProfessor VARCHAR(64) NOT NULL,
disciplinaProfessor VARCHAR(20) NOT NULL
);

CREATE TABLE tbDisciplinas(
idDisciplina INT(2) AUTO_INCREMENT PRIMARY KEY NOT NULL,
nomeDisciplina VARCHAR(20) NOT NULL
);

ALTER TABLE tbAlunos ADD serieAluno VARCHAR(25) NOT NULL;

CREATE TABLE tbSerie(
idSerie INT(2) AUTO_INCREMENT PRIMARY KEY NOT NULL,
nomeSerie VARCHAR(25) NOT NULL
);

INSERT INTO tbAlunos(idAluno, nomeAluno, idadeAluno, enderecoAluno, telefoneAluno, emailAluno, cpfAluno, rgAluno, serieAluno)
VALUES
(1, "Carlinhos da Silva", 11, "Rua João Cordeiro, 21", "84 95545-5456", "carlos@hotmail.com", "654.658.952-56", "54ads4d56", "6ª serie - Fundamental");

INSERT INTO tbSerie(idSerie, nomeSerie)
VALUES
(2, "2ª serie - Fundamental"),
(3, "3ª serie - Fundamental"),
(4, "4ª serie - Fundamental"),
(5, "5ª serie - Fundamental"),
(6, "6ª serie - Fundamental"),
(7, "7ª serie - Fundamental"),
(8, "8ª serie - Fundamental"),
(9, "9ª serie - Fundamental"),
(10, "1º ano - Medio"),
(11, "2º ano - Medio"),
(12, "3º ano - Medio")
SHOW TABLES