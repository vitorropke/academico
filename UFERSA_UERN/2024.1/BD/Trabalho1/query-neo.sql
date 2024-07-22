CREATE TABLE planeta (
    id          SERIAL PRIMARY KEY,
    nome        VARCHAR(64) UNIQUE NOT NULL,
    populacao   INT8 NOT NULL
);

CREATE TABLE satelite (
    id          SERIAL PRIMARY KEY,
    nome        VARCHAR(64) UNIQUE NOT NULL,
    massa       FLOAT8 NOT NULL,
    tamanho     REAL NOT NULL,
    velocidade  REAL NOT NULL,
    id_planeta  SERIAL NOT NULL REFERENCES planeta
);

CREATE TABLE meteorito (
    id          SERIAL PRIMARY KEY,
    nome        VARCHAR(64) UNIQUE NOT NULL,
    massa       FLOAT8 NOT NULL,
    tamanho     REAL NOT NULL,
    id_planeta  SERIAL NOT NULL REFERENCES planeta
);

INSERT INTO planeta (nome, populacao) VALUES
    ('Terra', 8.1*10^9),
    ('Marte', 1);
SELECT * FROM planeta;

INSERT INTO satelite (nome, massa, tamanho, velocidade, id_planeta) VALUES
    ('abc456', 5484846, 200, 10000, 1),
    ('AAAAA', 4566, 3, 7000, 1),
    ('F', 564211, 30, 12000, 2),
    ('Cheliabinsk', 10^6, 20, 19000, 1),
    ('Chicxulub', 10^14, 10000, 20000, 1);
SELECT * FROM satelite;

UPDATE planeta SET populacao = 10 WHERE nome = 'Marte';
SELECT * FROM planeta WHERE nome = 'Marte';

CREATE FUNCTION populacao_afetada(massa FLOAT8, tamanho REAL, velocidade REAL, densidade_populacional REAL) RETURNS INT8
    --AS 'SELECT trunc((0.5*$1*$3^2)/(10^9+pi()*$2^2)/$4);'
    LANGUAGE SQL
    RETURN trunc((0.5*massa*velocidade^2)/(10^9+pi()*tamanho^2)/densidade_populacional);
SELECT populacao_afetada(10^6, 20, 19000, 60.29);

CREATE FUNCTION reducao_massa(massa FLOAT8, velocidade REAL) RETURNS FLOAT8
    LANGUAGE SQL
    RETURN massa/(0.8*velocidade);
SELECT reducao_massa(10^6, 19000);

CREATE FUNCTION reducao_tamanho(massa FLOAT8, tamanho REAL, velocidade REAL) RETURNS REAL
    LANGUAGE SQL
    RETURN tamanho*(reducao_massa(massa, velocidade)/massa)^(1.0/3.0);
SELECT reducao_tamanho(10^6, 20, 19000);

CREATE FUNCTION queda_meteorito() RETURNS TRIGGER AS $queda_meteorito$
    DECLARE
        pessoas_mortas INT8 := populacao_afetada(OLD.massa, OLD.tamanho, OLD.velocidade, 60.29);
        populacao_planeta INT8;
    BEGIN
        INSERT INTO meteorito(nome, massa, tamanho, id_planeta)
            VALUES (OLD.nome, reducao_massa(OLD.massa, OLD.velocidade), reducao_tamanho(OLD.massa, OLD.tamanho, OLD.velocidade), OLD.id_planeta);
        
        SELECT populacao INTO populacao_planeta FROM planeta WHERE id = OLD.id_planeta;
        IF pessoas_mortas >= populacao_planeta THEN
            UPDATE planeta SET populacao = 0 WHERE id = OLD.id_planeta;
        ELSE
            UPDATE planeta SET populacao = populacao_planeta - pessoas_mortas WHERE id = OLD.id_planeta;
        END IF;
        RETURN NULL;
    END;
$queda_meteorito$LANGUAGE plpgsql;

CREATE TRIGGER queda_meteorito AFTER DELETE ON satelite
    FOR EACH ROW EXECUTE FUNCTION queda_meteorito();

DELETE FROM satelite WHERE nome = 'Cheliabinsk';

