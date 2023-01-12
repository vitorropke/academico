#include <iostream> //Inclus�o da biblioteca 'iostream' que controla a leitura e grava��o para fluxos padr�o
#include "concurso.h" //Inclus�o do cabe�alho 'concurso' que possui os prot�tipos e registros

using namespace std;

int main()
{
	int numeroDeParticipantes, numeroDeQuestoes; //Declara��o das vari�veis 'numeroDeParticipantes' e 'numeroDeQuestoes' de tipo inteiro
	
	cout << "Qual o n" << char(163) << "mero de participantes? "; //Sa�da de caracteres
	cin >> numeroDeParticipantes; //Entrada para a vari�vel 'numeroDeParticipantes'
	cout << "Qual o n" << char(163) << "mero de quest" << char(228) << "es? "; //Sa�da de caracteres
	cin >> numeroDeQuestoes; //Entrada para a vari�vel 'numeroDeQuestoes'

	questoes * questao = new questoes[numeroDeQuestoes]; //Declara��o do vetor din�mico
	estatistica * estatisticas = new estatistica[numeroDeQuestoes]; //Declara��o da vari�vel 'estatisticas' como registro

	for (int i = 0; i < numeroDeParticipantes; ++i) //La�o de repeti��o com in�cio em 0, incremento 1 para cada loop e a vari�vel 'numeroDeParticipantes' como condi��o de parada de acordo com o n�mero de participantes que o usu�rio colocou
	{
		imprimirSeparadores('=', 34); //Fun��o para imprimir os tra�os
		cout << endl;

		cout << endl;
		cout << "Participante " << i + 1 << endl;
		imprimirSeparadores('-', 14); //Fun��o para imprimir os tra�os
		cout << endl;

		for (int j = 0; j < numeroDeQuestoes; ++j) //La�o de repeti��o com in�cio em 0, incremento 1 para cada loop e a vari�vel 'numeroDeQuestoes' como condi��o de parada de acordo com o n�mero de quest�es que o usu�rio colocou
		{
			cout << "Quest" << char(198) << "o " << char(j + 65) << endl;

			cout.width(20); //Espa�o para alinhar o texto
			cout << "Dificuldade: ";
			cin >> questao->dificuldade;
			
			cout.width(9); //Espa�o para alinhar o texto
			cout << "In" << char(161) << "cio: ";
			cin >> questao->inicio.hora; //Entrada para a vari�vel 'questao.inicio.hora'
			cin.ignore(); //Ignorar caracteres entre as vari�veis hora e minuto
			cin >> questao->inicio.minuto; //Entrada para a vari�vel 'questao.inicio.minuto'
			
			cout.width(12); //Espa�o para alinhar o texto
			cout << "Fim: ";
			cin >> questao->fim.hora; //Entrada para a vari�vel 'questao.fim.hora'
			cin.ignore(); //Ignorar caracteres entre as vari�veis hora e minuto
			cin >> questao->fim.minuto; //Entrada para a vari�vel 'questao.fim.minuto'

			estatisticas[j] = mediaDasCoisas(questao, numeroDeQuestoes, 0, 1); //Chamando a fun��o que calcula as m�dias e atribuindo-a a uma vari�vel			
			cout << endl;
		}
		cout << endl;
	}

	imprimirSeparadores('=', 34); //Fun��o para imprimir os tra�os
	cout << endl;
	cout << endl;

	cout << "Estat" << char(161) << "sticas" << endl;
	imprimirSeparadores('-', 12); //Fun��o para imprimir os tra�os
	cout << endl;

	for (int i = 0; i < numeroDeQuestoes; ++i) //La�o de repeti��o com in�cio em 0, incremento 1 para cada loop e a vari�vel 'numeroDeQuestoes' como condi��o de parada de acordo com o n�mero de quest�es que o usu�rio colocou
	{
		cout << "Quest" << char(198) << "o " << char(i + 65) << ": Dificuldade m" << char(130) << "dia (";
		cout << estatisticas[i].dificuldadeMedia;
		cout << ") - Tempo m" << char(130) << "dio (";
		cout << estatisticas[i].tempoMedio;
		cout << " minutos)" << endl;
	}

	cout << "Concurso : Dificuldade m" << char(130) << "dia (";
	cout << estatisticas[0].dificuldadeMedia;
	cout << ") - Tempo m" << char(130) << "dio (";
	cout << estatisticas[0].tempoMedio;
	cout << " minutos)" << endl;

	delete[] questao; //Apagando o vetor din�mico para liberar espa�o na mem�ria
	delete[] estatisticas;

	system("pause>>null");
	return 0;
}