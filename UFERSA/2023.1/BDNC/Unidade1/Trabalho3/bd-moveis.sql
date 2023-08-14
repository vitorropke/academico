CREATE TABLE "relatos" (
	"id"	INTEGER NOT NULL,
	"latitude"	REAL NOT NULL,
	"longitude"	REAL NOT NULL,
	"data"	TEXT NOT NULL,
	"hora"	TEXT NOT NULL,
	"duracao"	INTEGER NOT NULL,
	"azimute_inicial"	INTEGER NOT NULL,
	"elevacao_inicial"	INTEGER NOT NULL,
	"azimute_final"	INTEGER NOT NULL,
	"elevacao_final"	INTEGER NOT NULL,
	"magnitude"	INTEGER NOT NULL,
	"cor"	TEXT NOT NULL,
	"som"	INTEGER NOT NULL,
	"rastro"	INTEGER NOT NULL,
	"explosao"	INTEGER NOT NULL,
	"observacoes"	TEXT,
	PRIMARY KEY("id" AUTOINCREMENT)
);

INSERT INTO "relatos" VALUES (
0,
-5.206940, -37.324059,
"2023-08-04", "22:50", 2,
54, 30,
68, 23,
-5,
"branco",
0,
0,
0,
NULL
);

SELECT * FROM "relatos";

UPDATE "relatos"
SET "cor" = "amarelo"
WHERE "id" = 0;

SELECT * FROM "relatos";

DELETE FROM "relatos"
WHERE "id" = 0;

SELECT * FROM "relatos";
