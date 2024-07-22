CREATE DOMAIN pitch_domain AS REAL
    CHECK(VALUE >= -90.0 AND VALUE <= 90.0);
CREATE DOMAIN yaw_domain AS REAL
    CHECK(VALUE >= -180.0 AND VALUE <= 180.0);
CREATE DOMAIN roll_domain AS REAL
    CHECK(VALUE >= -180.0 AND VALUE <= 180.0);

CREATE TABLE nave (
    id      SERIAL PRIMARY KEY,
    nome    VARCHAR(64) UNIQUE NOT NULL,
    pitch   pitch_domain NOT NULL,
    yaw     yaw_domain NOT NULL,
    roll    roll_domain NOT NULL
);

CREATE DOMAIN idade_domain AS INT2
    CHECK(VALUE >= 0);

CREATE TABLE pessoa (
    id      SERIAL PRIMARY KEY,
    nome    VARCHAR(64) NOT NULL,
    idade   idade_domain NOT NULL
);

CREATE TABLE comandante (
    id                      SERIAL PRIMARY KEY,
    data_inicio_carreira    DATE,
    id_pessoa               SERIAL UNIQUE NOT NULL REFERENCES pessoa
);

CREATE DOMAIN cabine_domain AS INT2
    CHECK(VALUE > 0);

CREATE TABLE passageiro (
    id          SERIAL PRIMARY KEY,
    cabine      cabine_domain NOT NULL,
    id_pessoa   SERIAL UNIQUE NOT NULL REFERENCES pessoa
);

INSERT INTO nave (nome, pitch, yaw, roll) VALUES ('Axiom', 0.0, 0.0, 0.0);
SELECT * FROM nave;

INSERT INTO pessoa (nome, idade) VALUES
    ('B. McCrea', 30),
    ('Yi Long Ma', 46);
SELECT * FROM pessoa;

INSERT INTO comandante (data_inicio_carreira, id_pessoa) VALUES
    ('2775-01-01', 1),
    (NULL, 2);
SELECT * FROM comandante;

SELECT c.id, p.nome, p.idade, c.data_inicio_carreira, c.id_pessoa
    FROM comandante c JOIN pessoa p ON c.id_pessoa = p.id;

INSERT INTO pessoa (nome, idade) VALUES
    ('Ea', 20),
    ('Sicrano', 32);
SELECT * FROM pessoa;

INSERT INTO passageiro (cabine, id_pessoa) VALUES
    (120, 3),
    (8, 4);
SELECT * FROM passageiro;

SELECT pa.id, p.nome, p.idade, pa.cabine, pa.id_pessoa
    FROM passageiro pa JOIN pessoa p ON pa.id_pessoa = p.id;

-- COMMIT e ROLLBACK
SELECT * FROM nave;
BEGIN;
    UPDATE nave SET pitch = 10.0;
ROLLBACK;
SELECT * FROM nave;

BEGIN;
    UPDATE nave SET pitch = 20.0;
COMMIT;
SELECT * FROM nave;

-- Integridade de domínio
INSERT INTO pessoa (nome, idade) VALUES (24, 'abc');
SELECT * FROM pessoa;

-- Integridade referencial
SELECT * FROM pessoa;
INSERT INTO comandante (data_inicio_carreira, id_pessoa) VALUES ('2050-01-01', 6);
SELECT * FROM comandante;

-- Integridade de vazio
SELECT * FROM pessoa;
INSERT INTO comandante (data_inicio_carreira, id_pessoa) VALUES (NULL, NULL);
SELECT * FROM comandante;

--Integridade de chave
SELECT * FROM pessoa;
SELECT * FROM comandante;
INSERT INTO comandante (id, data_inicio_carreira, id_pessoa) VALUES (2, '2050-01-01', 0);
SELECT * FROM comandante;

-- Integridade definida pelo usuário
SELECT * FROM pessoa;
INSERT INTO pessoa (nome, idade) VALUES ('Sicrano', -2);
SELECT * FROM pessoa;

-- Controle de acesso
CREATE ROLE comandante_role OPTION LOGIN PASSWORD '1';
CREATE ROLE passageiro_role OPTION LOGIN PASSWORD '1';

GRANT SELECT ON nave TO comandante_role;
GRANT UPDATE ON nave TO comandante_role;
GRANT SELECT ON nave TO passageiro_role;

UPDATE nave SET pitch = 10.0;
UPDATE nave SET roll = 85.0;

-- Concorrência
BEGIN;
UPDATE nave SET pitch = 30.0;
UPDATE nave SET yaw = 2.0;
UPDATE nave SET roll = 85.0;
END;

-- Backup
pg_dump nave > '/home/vitor/viagem_espacial';
DROP DATABASE viagem_espacial;
psql nave < '/home/vitor/viagem_espacial';
