#pragma once

struct horario //Registro 'horário'
{
	int hora, minuto; //Registro possuindo duas variáveis inteiras
};

struct questoes //Registro 'questoes'
{
	int dificuldade; //Variável inteira
	horario inicio, fim; //Variáveis que possuem tipos do registro 'horario'
};

struct estatistica //Registro 'estatistica'
{
	float dificuldadeMedia, tempoMedio; //Variáveis tipo float
};

int numeroDeMinutos(horario, horario); //Parametro da função 'numeroDeminutos'
struct estatistica mediaDasCoisas(questoes [], int, int, int); //Parametro da função-registro 'mediaDasCoisas'
void imprimirSeparadores(char, int); //Parametro da função 'imprimirSeparadores'