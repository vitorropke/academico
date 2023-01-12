#include <iostream> //Inclusão da biblioteca 'iostream' que controla a leitura e gravação para fluxos padrão
#include "concurso.h" //Inclusão do cabeçalho 'concurso' que possui os protótipos e registros

using namespace std;

int main()
{
	int numeroDeParticipantes, numeroDeQuestoes; //Declaração das variáveis 'numeroDeParticipantes' e 'numeroDeQuestoes' de tipo inteiro
	
	cout << "Qual o n" << char(163) << "mero de participantes? "; //Saída de caracteres
	cin >> numeroDeParticipantes; //Entrada para a variável 'numeroDeParticipantes'
	cout << "Qual o n" << char(163) << "mero de quest" << char(228) << "es? "; //Saída de caracteres
	cin >> numeroDeQuestoes; //Entrada para a variável 'numeroDeQuestoes'

	questoes * questao = new questoes[numeroDeQuestoes]; //Declaração do vetor dinâmico
	estatistica * estatisticas = new estatistica[numeroDeQuestoes]; //Declaração da variável 'estatisticas' como registro

	for (int i = 0; i < numeroDeParticipantes; ++i) //Laço de repetição com início em 0, incremento 1 para cada loop e a variável 'numeroDeParticipantes' como condição de parada de acordo com o número de participantes que o usuário colocou
	{
		imprimirSeparadores('=', 34); //Função para imprimir os traços
		cout << endl;

		cout << endl;
		cout << "Participante " << i + 1 << endl;
		imprimirSeparadores('-', 14); //Função para imprimir os traços
		cout << endl;

		for (int j = 0; j < numeroDeQuestoes; ++j) //Laço de repetição com início em 0, incremento 1 para cada loop e a variável 'numeroDeQuestoes' como condição de parada de acordo com o número de questões que o usuário colocou
		{
			cout << "Quest" << char(198) << "o " << char(j + 65) << endl;

			cout.width(20); //Espaço para alinhar o texto
			cout << "Dificuldade: ";
			cin >> questao->dificuldade;
			
			cout.width(9); //Espaço para alinhar o texto
			cout << "In" << char(161) << "cio: ";
			cin >> questao->inicio.hora; //Entrada para a variável 'questao.inicio.hora'
			cin.ignore(); //Ignorar caracteres entre as variáveis hora e minuto
			cin >> questao->inicio.minuto; //Entrada para a variável 'questao.inicio.minuto'
			
			cout.width(12); //Espaço para alinhar o texto
			cout << "Fim: ";
			cin >> questao->fim.hora; //Entrada para a variável 'questao.fim.hora'
			cin.ignore(); //Ignorar caracteres entre as variáveis hora e minuto
			cin >> questao->fim.minuto; //Entrada para a variável 'questao.fim.minuto'

			estatisticas[j] = mediaDasCoisas(questao, numeroDeQuestoes, 0, 1); //Chamando a função que calcula as médias e atribuindo-a a uma variável			
			cout << endl;
		}
		cout << endl;
	}

	imprimirSeparadores('=', 34); //Função para imprimir os traços
	cout << endl;
	cout << endl;

	cout << "Estat" << char(161) << "sticas" << endl;
	imprimirSeparadores('-', 12); //Função para imprimir os traços
	cout << endl;

	for (int i = 0; i < numeroDeQuestoes; ++i) //Laço de repetição com início em 0, incremento 1 para cada loop e a variável 'numeroDeQuestoes' como condição de parada de acordo com o número de questões que o usuário colocou
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

	delete[] questao; //Apagando o vetor dinâmico para liberar espaço na memória
	delete[] estatisticas;

	system("pause>>null");
	return 0;
}