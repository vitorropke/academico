CREATE TYPE tipo_motor AS (
	fabricante varchar(50),
	modelo varchar(50),
	potencia integer
);

CREATE TABLE motores OF tipo_motor;

CREATE TABLE avioes (
	fabricante varchar(50),
	modelo varchar(50),
	num_motores integer,
	motor tipo_motor,
	num_assentos integer
);

CREATE TABLE avioes_passageiros (
	classes varchar(20)[4]
) INHERITS (avioes);

INSERT INTO avioes_passageiros VALUES (
	'Airbus',
	'A321neo',
	2,
	ROW('CFM International', 'CFM56', 8840),
	200,
	ARRAY['economica', 'executiva']
);

SELECT * FROM avioes_passageiros;

UPDATE avioes_passageiros SET motor = ('Pratt & Whitney', 'PW1000G', 12544) WHERE fabricante = 'Airbus';

SELECT * FROM avioes_passageiros;

INSERT INTO avioes_passageiros VALUES (
	'Airbus',
	'A320neo',
	2,
	ROW('CFM', 'nada', 10),
	200,
	ARRAY['economica', 'executiva']
);

SELECT * FROM avioes_passageiros;

DELETE FROM avioes_passageiros WHERE (motor).potencia < 5000; 

SELECT * FROM avioes_passageiros;

CREATE TABLE avioes_militares (
	armamentos varchar(50)[4]
) INHERITS (avioes);

INSERT INTO avioes_militares VALUES (
	'General Dynamics',
	'F-16B',
	1,
	ROW('Pratt & Whitney', 'F100-PW-100', 10854),
	2,
	ARRAY['AIM-9 Sidewinder', 'AIM-7 Sparrow', 'AIM-120 AMRAAM']
);

SELECT * FROM avioes_militares;
SELECT * FROM avioes_passageiros;
SELECT * FROM avioes;

CREATE VIEW avancado AS
	SELECT * FROM avioes_passageiros WHERE (motor).potencia > 7000 AND 'executiva' = ANY(classes);

SELECT * FROM avancado;
