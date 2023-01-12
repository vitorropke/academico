#pragma once

struct horario //Registro 'hor�rio'
{
	int hora, minuto; //Registro possuindo duas vari�veis inteiras
};

struct questoes //Registro 'questoes'
{
	int dificuldade; //Vari�vel inteira
	horario inicio, fim; //Vari�veis que possuem tipos do registro 'horario'
};

struct estatistica //Registro 'estatistica'
{
	float dificuldadeMedia, tempoMedio; //Vari�veis tipo float
};

int numeroDeMinutos(horario, horario); //Parametro da fun��o 'numeroDeminutos'
struct estatistica mediaDasCoisas(questoes [], int, int, int); //Parametro da fun��o-registro 'mediaDasCoisas'
void imprimirSeparadores(char, int); //Parametro da fun��o 'imprimirSeparadores'