DROP DATABASE dbEscola;
CREATE DATABASE dbEscola;
USE dbEscola;

CREATE TABLE tbAlunos(
idAluno INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
NomeCompleto VARCHAR(40) NOT NULL,
Idade INT(2) NOT NULL,
CPF CHAR(14) NOT NULL,
RG VARCHAR(15) NOT NULL,
Endereco VARCHAR(40) NOT NULL,
Telefone VARCHAR(20) NOT NULL,
Email VARCHAR(40) NOT NULL,
CodSerie INT NOT NULL
);
ALTER TABLE tbAlunos MODIFY Idade INT(3) NOT NULL;

CREATE TABLE tbProfessores(
idProfessor INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
NomeCompleto VARCHAR(40) NOT NULL,
Idade INT(2) NOT NULL,
CPF CHAR(14) NOT NULL,
RG VARCHAR(15) NOT NULL,
Endereco VARCHAR(40) NOT NULL,
Telefone VARCHAR(20) NOT NULL,
Email VARCHAR(40) NOT NULL,
Salario DECIMAL(7,2) NOT NULL,
CodDisciplina INT NOT NULL
);
ALTER TABLE tbProfessores MODIFY Idade INT(3) NOT NULL;

CREATE TABLE tbDisciplinas(
idDisciplina INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
Nome VARCHAR(20) NOT NULL
);
ALTER TABLE tbDisciplinas MODIFY Nome VARCHAR(400) NOT NULL;

CREATE TABLE tbSeries(
idSerie INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
Serie VARCHAR(13) NOT NULL
);
ALTER TABLE tbSeries MODIFY Serie VARCHAR(2000) NOT NULL;

ALTER TABLE tbAlunos ADD FOREIGN KEY (CodSerie) REFERENCES tbSeries (idSerie);
ALTER TABLE tbProfessores ADD FOREIGN KEY (CodDisciplina) REFERENCES tbDisciplinas (idDisciplina);

SHOW TABLES;
INSERT INTO tbDisciplinas (idDisciplina, Nome)
VALUES
(1, "Artes"),
(2, "Biologia"),
(3, "Ciências"),
(4, "Educação Física"),
(5, "Espanhol"),
(6, "Filosofia"),
(7, "Física"),
(8, "Geografia"),
(9, "Gramática"),
(10, "História"),
(11, "Inglês"),
(12, "Literatura"),
(13, "Matemática"),
(14, "Português"),
(15, "Química"),
(16, "Sociologia");

INSERT INTO tbSeries (idSerie, Serie)
VALUES
(1, "1º ano - EF"),
(2, "2º ano - EF"),
(3, "3º ano - EF"),
(4, "4º ano - EF"),
(5, "5º ano - EF"),
(6, "6º ano - EF"),
(7, "7º ano - EF"),
(8, "8º ano - EF"),
(9, "9º ano - EF"),
(10, "1º ano - EM"),
(11, "2º ano - EM"),
(12, "3º ano - EM");

INSERT INTO tbProfessores (idProfessor, NomeCompleto, Idade, CPF, RG, Endereco, Telefone, Email, Salario, CodDisciplina)
VALUES
(1, "Artêmio da Mota", 32, "032.345.645-79", "434.323.534", "Rua Francisco Guerra, 48", "+55 84 99423-2354", "artemio_m@hotmail.com", 2250.34, 1),
(2, "Eusébio de Souza", 43, "032.423.456-44", "004.322.755", "Rua Moreira Franco, 323", "+55 84 99433-9584", "eusebio_souza@hotmail.com", 2237.87, 2),
(3, "Graciela Oliveira", 28, "345.765.125-77", "954.767.989", "Avenida Emílio da Silva, 155", "+55 84 98787-5645", "graciela_oli@hotmail.com", 2443.56, 3),
(4, "Eduardo Pereira da Mota", 30, "343.456.867-11", "333.567.987", "Rua Gonçalves Dias, 111", "+55 84 90939-1123", "edu_pe_mo@hotmail.com", 2777.65, 4),
(5, "Espânio Francisco", 33, "998.345.223-11", "432.454.198", "Avenida Fagundes Guerra, 88", "+55 84 98987-7776", "espanio_fran@hotmail.com", 3954.22, 5),
(6, "Filomena Gomes", 30, "904.452.777-79", "223.543.778", "Rua Donaldo Antunes, 78", "+55 84 90977-7767", "filo_gomes@hotmail.com", 2778.87, 6),
(7, "Figueiredo da Cunha", 33, "990.323.112-10", "022.043.232", "Avenida Silva Jardim, 49", "+55 84 99999-9990", "figueiredo_cunha@hotmail.com", 2333.45, 7),
(8, "Geovana Martins", 32, "453.238.956-55", "856.343.767", "Rua Cunha da Mota, 12", "+55 84 98862-9730", "geo_martins@hotmail.com", 2534.78, 8),
(9, "Graciliano da Mota", 32, "032.346.646-79", "434.324.535", "Rua Francisco Guerra, 48", "+55 84 99423-2355", "graciliano_mota@hotmail.com", 2887.54, 9),
(10, "Hilda da Mota", 30, "032.347.647-80", "435.325.536", "Rua Francisco Guerra, 49", "+55 84 99423-2399", "hildamota@hotmail.com", 2887.32, 10),
(11, "Inês da Cunha", 33, "990.324.113-19", "022.044.234", "Avenida Silva Jardim, 49", "+55 84 99999-9991", "ines_cunha@hotmail.com", 2345.78, 11),
(12, "Lito Cabral", 35, "334.553.223-33", "332.334.133", "Avenida Presidente Dutra, 988", "+55 84 92322-1231", "litocabral@hotmail.com", 2890.67, 12),
(13, "Mateus Fagundes", 33, "432.111.113-66", "532.098.129", "Rua Dias de Hoje, 90", "+55 84 93232-2111", "mateusf@hotmail.com", 2349.90, 13),
(14, "Joaquim Milton", 38, "755.976.087-22", "444.877.344", "Avenida Alberto Maranhão, 99", "+55 84 99819-9470", "joaquimmmilton@hotmail.com", 3322.45, 14),
(15, "Quimberlim Fonseca", 22, "142.758.123-4", "025.023.085", "Avenida Roberto Aragão, 52", "+55 84 94008-9470", "quimberlim_fon@hotmail.com", 3333.33, 15),
(16, "Souza Solto", 38, "955.457.124-65", "458.742.396", "Avenida Costa E Silva, 15", "+55 84 95954-4567", "souza_solto@hotmail.com", 3000.45, 16);

INSERT INTO tbAlunos (idAluno, NomeCompleto, Idade, CPF, RG, Endereco, Telefone, Email, CodSerie)
VALUES
(1, "Arnaldo Antunes", 5, "757.124.688-12", "323.645.756", "Avenida Rio Branco, 34", "+55 84 99819-9642", "arnaldo_an@hotmail.com", 1),
(2, "Beatriz Dias", 6, "852.114.357-75", "456.999.233", "Avenida Doura Branco, 245", "+55 84 99642-7700", "bia_dias@hotmail.com", 1),
(3, "Carlos Bezerra", 5, "753.159.357-95", "741.575.025", "Avenida Dantas Branco, 456", "+55 84 75757-7575", "carlos_bez@hotmail.com", 1),
(4, "Daniela Rodrigues", 5, "951.123.456-78", "014.502.065", "Avenida Maré Branco, 755", "+55 84 77575-7575", "daniela_rod@hotmail.com", 1),
(5, "Euzébio Dantas", 5, "789.456.123-10", "042.405.056", "Avenida Poeta Branco, 125", "+55 84 55757-7575", "euzebio@hotmail.com", 1),
(6, "Francisco José Júnior", 5, "014.147.352-66", "085.095.062", "Avenida Loló Branco, 234", "+55 84 42424-2424", "francisco_j_j@hotmail.com", 1),
(7, "Geovana da Costa", 6, "102.702.103-77", "082.365.025", "Avenida Teté Branco, 789", "+55 83 75757-1240", "geo_costa@hotmail.com", 1),
(8, "Hélio Fernandes", 7, "052.740.520-00", "785.777.777", "Avenida Silva Branco, 354", "+55 84 25254-0424", "helio_fer@hotmail.com", 1),
(9, "Izaque Moisés", 5, "001.045.065-08", "777.777.777", "Avenida Outro Branco, 66", "+55 84 04277-0445", "izaque_moises@hotmail.com", 1),
(10, "Joana Josefa", 5, "078.045.098-88", "888.888.888", "Avenida Branquelo Branco, 88", "+55 84 04247-04345", "joana_josefa@hotmail.com", 1);

SELECT * FROM tbAlunos;
SELECT * FROM tbDisciplinas;
SELECT * FROM tbProfessores;
SELECT * FROM tbSeries;

SELECT NomeCompleto, Idade, CodSerie FROM tbAlunos;
SELECT idDisciplina, Nome FROM tbDisciplinas;
SELECT NomeCompleto, Idade, Salario FROM tbProfessores;
SELECT idSerie, Serie FROM tbSeries;

SELECT NomeCompleto FROM tbAlunos WHERE idAluno=5;
SELECT NomeCompleto FROM tbProfessores WHERE idProfessor=5;
SELECT Nome FROM tbDisciplinas WHERE idDisciplina=5;
SELECT Serie FROM tbSeries WHERE idSerie=5;

SELECT * FROM tbAlunos JOIN tbSeries ON tbAlunos.CodSerie = tbSeries.idSerie;
SELECT * FROM tbProfessores JOIN tbDisciplinas ON tbProfessores.CodDisciplina = tbDisciplinas.idDisciplina;

UPDATE tbProfessores SET NomeCompleto = "Francisco José" WHERE idProfessor = 1;
UPDATE tbAlunos SET NomeCompleto = "Francisco José" WHERE idAluno = 1;
UPDATE tbSeries SET Serie = "Maternal" WHERE idSerie = 1;
UPDATE tbDisciplinas SET Nome = "Estudos ambíguos" WHERE idDisciplina = 1;