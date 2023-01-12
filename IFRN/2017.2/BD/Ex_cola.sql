CREATE DATABASE bancoescola;
SHOW DATABASES;
USE bancoescola;
CREATE TABLE tbAlunos(
idAluno INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
nomeAluno VARCHAR(64) NOT NULL,
enderecoAluno VARCHAR(30) NOT NULL,
bairroAluno VARCHAR(20) NOT NULL,
foneAluno VARCHAR(15) NOT NULL,
emailAluno VARCHAR(20) NOT NULL,
idadeAluno INT(3) NOT NULL
);
SHOW TABLES;
DESCRIBE tbAlunos;
ALTER TABLE tbAlunos ADD dataNiver DATE NOT NULL AFTER idadeAluno;
ALTER TABLE tbAlunos CHANGE foneAluno telAluno VARCHAR(18) NOT NULL;
ALTER TABLE tbAlunos DROP bairroAluno;
CREATE TABLE tbProfessores(
idProfessor INT(10) NOT NULL PRIMARY KEY AUTO_INCREMENT,
nomeProfessor VARCHAR(45) NOT NULL,
enderecoProfessor VARCHAR(45) NOT NULL,
telefoneProfessor VARCHAR(15),
emailProfessor VARCHAR(45),
idadeProfessor INT(2) NOT NULL,
cpfProfessor VARCHAR(11) NOT NULL,
DataNiverProfessor DATE NOT NULL
);