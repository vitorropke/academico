#include <iostream>
#include "funcoesGerador.h"
#include <fstream>

using namespace std;

int main()
{
	int opcao, vetorAtual = 0, alterarCarta, excluirCarta, posicaoDoVetor = 0; //Variaveis de tipo inteiro
	aviao vetorCartas[31]; //Vetor de registro

	ifstream fin; // cria objeto para leitura de arquivo
	fin.open("avioes.dat", ios_base::in | ios_base::binary);
	
	if (fin.is_open()) //se o arquivo foi aberto sem erros
	{
		while (fin.read((char*)&vetorCartas[posicaoDoVetor], sizeof(aviao)))
			posicaoDoVetor += 1; //Incremento da posição do vetor
		fin.close();
	}

	imprimirMenuDeOpcoes(); //Função de imprimir menu
	
	cout << endl;

	cout << "Escolha uma opcao [_]\b\b"; //Opção de comando para as cartas
	cin >> opcao;

	cout << endl;

	while (opcao != 5)
	{
		if (opcao == 1) //Cadastrar cartas
		{
			cout << endl;
			cout << "Cadastrar Carta\n";
			imprimirTraco(15, '-');
			cout << endl;
			
			//Nas próximas linhas de comando dentro desta condicional são vários valores de entrada e saída para informar os dados do avião no vetor atual
			cout << "Fabricante                     : ";
			cin >> vetorCartas[vetorAtual].fabricante; //Comando para entrada de dados no vetorCartas, sendo ele um registro de vetores. O 'vetorAtual' é a variável que diz em qual índice de vetor estamos
			cout << "Modelo                         : ";
			cin >> vetorCartas[vetorAtual].modelo;
			cout << "Preco (milhoes de US$)         : ";
			cin >> vetorCartas[vetorAtual].preco;
			cout << "Quantidade Produzida           : ";
			cin >> vetorCartas[vetorAtual].quantidadeProduzida;
			cout << "Ano do primeiro voo            : ";
			cin >> vetorCartas[vetorAtual].anoPrimeiroVoo;
			cout << "Numero de passageiros          : ";
			cin >> vetorCartas[vetorAtual].passageiros;
			cout << "Massa (vazio) (milhares de Kg) : ";
			cin >> vetorCartas[vetorAtual].massa;
			cout << "Quantidade de motores          : ";
			cin >> vetorCartas[vetorAtual].quantidadeMotores;
			cout << "Velocidade maxima (Km/h)       : ";
			cin >> vetorCartas[vetorAtual].velocidadeMaxima;
			cout << "Velocidade cruzeiro (Km/h)     : ";
			cin >> vetorCartas[vetorAtual].velocidadeCruzeiro;
			cout << "Alcance (Km)                   : ";
			cin >> vetorCartas[vetorAtual].alcance;
			cout << "Teto maximo (metros)           : ";
			cin >> vetorCartas[vetorAtual].tetoMaximo;
			cout << endl;
		}
		else if (opcao == 2) //Atualizar cartas
		{
			cout << "Atualizar Cartas\n";
			imprimirTraco(16, '-');
			cout << endl;

			for (int x = 0; x <= vetorAtual; x++) //Listar os aviões cadastrados
				cout << x + 1 << ") " << vetorCartas[x].fabricante << " " << vetorCartas[x].modelo << endl;

			cout << endl;

			cout << "Digite o numero da carta: [_]\b\b";
			cin >> alterarCarta; //Entrada do usuário para a carta a ser alterada
			cout << endl;

			//Próximas linhas de código mostra cada dado do registro. O -1 é que o vetor começa a ser colocado a partir do 0 e o usuario começa a digitar a partir do 1
			cout << "Alterando Carta " << vetorCartas[alterarCarta - 1].fabricante << " " << vetorCartas[alterarCarta - 1].modelo << ":\n";
			
			cout << "Fabricante                     : " << vetorCartas[alterarCarta - 1].fabricante << endl;
			cout << "Modelo                         : " << vetorCartas[alterarCarta - 1].modelo << endl;
			cout << "Preco (milhoes de US$)         : " << vetorCartas[alterarCarta - 1].preco << endl;
			cout << "Quantidade Produzida           : " << vetorCartas[alterarCarta - 1].quantidadeProduzida << endl;
			cout << "Ano do primeiro voo            : " << vetorCartas[alterarCarta - 1].anoPrimeiroVoo << endl;
			cout << "Numero de passageiros          : " << vetorCartas[alterarCarta - 1].passageiros << endl;
			cout << "Massa (vazio) (milhares de Kg) : " << vetorCartas[alterarCarta - 1].massa << endl;
			cout << "Quantidade de motores          : " << vetorCartas[alterarCarta - 1].quantidadeMotores << endl;
			cout << "Velocidade maxima (Km/h)       : " << vetorCartas[alterarCarta - 1].velocidadeMaxima << endl;
			cout << "Velocidade cruzeiro (Km/h)     : " << vetorCartas[alterarCarta - 1].velocidadeCruzeiro << endl;
			cout << "Alcance (Km)                   : " << vetorCartas[alterarCarta - 1].alcance << endl;
			cout << "Teto maximo (metros)           : " << vetorCartas[alterarCarta - 1].tetoMaximo << endl;
			cout << endl;
		}
		else if (opcao == 3) //Excuir cartas
		{
			cout << "Excluir Carta\n";
			imprimirTraco(13, '-');
			cout << endl;

			for (int x = 0; x <= vetorAtual; x++) //Listar os aviões cadastrados
				cout << x + 1 << ") " << vetorCartas[x].fabricante << " " << vetorCartas[x].modelo << endl;

			cout << endl;

			cout << "Digite o numero da carta: [_]\b\b";
			cin >> excluirCarta; //Entrada do usuário para a carta a ser excluida
			cout << endl;

			cout << "Carta " << vetorCartas[excluirCarta - 1].fabricante << " " << vetorCartas[excluirCarta - 1].modelo << " foi excluida do baralho.\n";

			for (int x = excluirCarta - 1; x < vetorAtual; x++) //Comando para sobrescrever a carta escolhida com as cartas seguintes
				vetorCartas[x] = vetorCartas[x + 1];
			vetorAtual -= 1; //Diminui o tamanho do vetor pois um elemento foi excluido
		}
		else if (opcao == 4) //Listar cartas
		{
			cout << "Cartas no Baralho\n";
			imprimirTraco(17, '-');
			cout << endl;

			for (int x = 0; x <= vetorAtual; x++) //Mostra os dados dos registros. Todos os registros
			{
				cout << "#" << x + 1;
				cout << " " << vetorCartas[x].fabricante;
				cout << " " << vetorCartas[x].modelo;
				cout.width(7);
				cout << right << vetorCartas[x].preco;
				cout.width(7);
				cout << right << vetorCartas[x].quantidadeProduzida;
				cout.width(7);
				cout << right << vetorCartas[x].anoPrimeiroVoo;
				cout.width(7);
				cout << right << vetorCartas[x].passageiros;
				cout.width(7);
				cout << right << vetorCartas[x].massa;
				cout.width(7);
				cout << right << vetorCartas[x].quantidadeMotores;
				cout.width(7);
				cout << right << vetorCartas[x].velocidadeMaxima;
				cout.width(7);
				cout << right << vetorCartas[x].velocidadeCruzeiro;
				cout.width(7);
				cout << right << vetorCartas[x].alcance;
				cout.width(7);
				cout << right << vetorCartas[x].tetoMaximo;
				cout << endl;
			}
		}
		else if (opcao == 5) //Sai do programa
			break;
		else //Código caso a opção seja diferente das anteriores
			cout << "Num sei!\n" << endl;

		cout << endl;
		imprimirMenuDeOpcoes(); //Função de imprimir o menu
		
		cout << endl;

		cout << "Escolha um opcao [_]\b\b";
		cin >> opcao; //Variável recebe entrada do usuario

		cout << endl;

		if (opcao == 1)
			vetorAtual += 1; //Incremento do 'vetorAtual' caso seja necessário inserir mais aviões
	}
	
	ofstream fout; //Um objeto ofstream
	fout.open("avioes.dat", ios_base::out | ios_base::binary | ios_base::app); //fout usado para escrever em avioes.dat
	for (int x = 0; x <= vetorAtual; x++)
		fout.write((char*)&vetorCartas[x], sizeof(aviao)); //Salva o registro em um arquivo binário. Write recebe endereço de memória e tamanho em bytes
	fout.close();

	system("pause");
	return 0;
}