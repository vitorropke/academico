#include <iostream>
#include "funcoesJogo.h"
#include <fstream>

using namespace std;

int main()
{
	char novoJogo, jogador1[20], jogador2[20];
	int atributo, rodada = 1, pontosJogador1 = 0, pontosJogador2 = 0, numeroDeElementos = 0;
	int cartasJogador1[3], cartasJogador2[3];
	aviao vetorCartasCompleto[32];

	ifstream fin; //Cria objeto para leitura do arquivo
	fin.open("avioes.dat", ios_base::in | ios_base::binary);

	if (fin.is_open())
	{
		while (fin.read((char *)&vetorCartasCompleto[numeroDeElementos], sizeof aviao))
			numeroDeElementos += 1; //Incremento da variável que serve tanto para identificar a posição atual do vetor que vem do arquivo como também para contar quantos elementos têm nesse vetor
		fin.close();
	}

	aviao * vetorDinamicoAvioes = new aviao[numeroDeElementos]; //Vetor dinamico de registro
	vetorDinamicoAvioes = vetorCartasCompleto; //Vetor dinamico recebe o vetor completo

	cout << "Super Trunfo Futebol\n";
	imprimirTracos(20, '-');
	cout << endl;
	cout << "Iniciar nova partida? [S/N] ";
	cin >> novoJogo;

	while (novoJogo == 'S')
	{
		cout << "Jogador 1: "; //Entrada do nome dos jogadores
		cin >> jogador1;
		cout << "Jogador 2: ";
		cin >> jogador2;

		imprimirTracos(10, '-');
		cout << endl;
		
		for (int x = 0; x < 4; x++)
		{
			cartasJogador1[x] = rand() % 32 + 1;
			cartasJogador2[x] = rand() % 32 + 1;
		}

		for (int x = 0; x < 4; x++) //Laço de rodadas
		{
			cout << endl;

			if (rodada % 2 == 0) //Controle para aparecer jogador 1 ou jogador 2 em cada rodada diferente
				cout << "[" << jogador2 << "]\n";
			else
				cout << "[" << jogador1 << "]\n";
			cout << endl;

			cout << "Carta: "; //Cada dado da carta escolhida
			cout << " " << vetorDinamicoAvioes[x].fabricante;
			cout << " " << vetorDinamicoAvioes[x].modelo << "| ";
			cout << vetorDinamicoAvioes[x].preco << "| ";
			cout << vetorDinamicoAvioes[x].quantidadeProduzida << "| ";
			cout << vetorDinamicoAvioes[x].anoPrimeiroVoo << "| ";
			cout << vetorDinamicoAvioes[x].passageiros << "| ";
			cout << vetorDinamicoAvioes[x].massa << "| ";
			cout << vetorDinamicoAvioes[x].quantidadeMotores << "| ";
			cout << vetorDinamicoAvioes[x].velocidadeMaxima << "| ";
			cout << vetorDinamicoAvioes[x].velocidadeCruzeiro << "| ";
			cout << vetorDinamicoAvioes[x].alcance << "| ";
			cout << vetorDinamicoAvioes[x].tetoMaximo;
			cout << endl;
			imprimirAtributos();
			cout << "Escolha atributo [_]\b\b";
			cin >> atributo;
			cout << endl;

			switch (atributo) //Comparação dos atributos
			{
			case 1:
				if (vetorDinamicoAvioes[cartasJogador1[x]].preco > vetorDinamicoAvioes[cartasJogador2[x]].preco)
					pontosJogador1 += 2;
				else if ((vetorDinamicoAvioes[cartasJogador1[x]].preco < vetorDinamicoAvioes[cartasJogador2[x]].preco))
					pontosJogador2 += 2;
				else
				{
					pontosJogador1 += 1;
					pontosJogador2 += 1;
				}
				//Imprimir os dados da rodada atual
				cout << "[" << jogador1 << "] " << vetorDinamicoAvioes[cartasJogador1[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador1[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador1[x]].preco;
				cout << "[" << jogador2 << "] " << vetorDinamicoAvioes[cartasJogador2[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador2[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador2[x]].preco;
				cout << endl;
				break;
			case 2:
				if (vetorDinamicoAvioes[cartasJogador1[x]].quantidadeProduzida > vetorDinamicoAvioes[cartasJogador2[x]].quantidadeProduzida)
					pontosJogador1 += 2;
				else if ((vetorDinamicoAvioes[cartasJogador1[x]].quantidadeProduzida < vetorDinamicoAvioes[cartasJogador2[x]].quantidadeProduzida))
					pontosJogador2 += 2;
				else
				{
					pontosJogador1 += 1;
					pontosJogador2 += 1;
				}

				cout << "[" << jogador1 << "] " << vetorDinamicoAvioes[cartasJogador1[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador1[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador1[x]].quantidadeProduzida;
				cout << "[" << jogador2 << "] " << vetorDinamicoAvioes[cartasJogador2[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador2[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador2[x]].quantidadeProduzida;
				cout << endl;
				break;
			case 3:
				if (vetorDinamicoAvioes[cartasJogador1[x]].anoPrimeiroVoo > vetorDinamicoAvioes[cartasJogador2[x]].anoPrimeiroVoo)
					pontosJogador1 += 2;
				else if ((vetorDinamicoAvioes[cartasJogador1[x]].anoPrimeiroVoo < vetorDinamicoAvioes[cartasJogador2[x]].anoPrimeiroVoo))
					pontosJogador2 += 2;
				else
				{
					pontosJogador1 += 1;
					pontosJogador2 += 1;
				}

				cout << "[" << jogador1 << "] " << vetorDinamicoAvioes[cartasJogador1[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador1[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador1[x]].anoPrimeiroVoo;
				cout << "[" << jogador2 << "] " << vetorDinamicoAvioes[cartasJogador2[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador2[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador2[x]].anoPrimeiroVoo;
				cout << endl;
				break;
			case 4:
				if (vetorDinamicoAvioes[cartasJogador1[x]].passageiros > vetorDinamicoAvioes[cartasJogador2[x]].passageiros)
					pontosJogador1 += 2;
				else if ((vetorDinamicoAvioes[cartasJogador1[x]].passageiros < vetorDinamicoAvioes[cartasJogador2[x]].passageiros))
					pontosJogador2 += 2;
				else
				{
					pontosJogador1 += 1;
					pontosJogador2 += 1;
				}
				cout << "[" << jogador1 << "] " << vetorDinamicoAvioes[cartasJogador1[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador1[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador1[x]].passageiros;
				cout << "[" << jogador2 << "] " << vetorDinamicoAvioes[cartasJogador2[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador2[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador2[x]].passageiros;
				cout << endl;
				break;
			case 5:
				if (vetorDinamicoAvioes[cartasJogador1[x]].massa > vetorDinamicoAvioes[cartasJogador2[x]].massa)
					pontosJogador1 += 2;
				else if ((vetorDinamicoAvioes[cartasJogador1[x]].massa < vetorDinamicoAvioes[cartasJogador2[x]].massa))
					pontosJogador2 += 2;
				else
				{
					pontosJogador1 += 1;
					pontosJogador2 += 1;
				}
				cout << "[" << jogador1 << "] " << vetorDinamicoAvioes[cartasJogador1[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador1[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador1[x]].massa;
				cout << "[" << jogador2 << "] " << vetorDinamicoAvioes[cartasJogador2[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador2[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador2[x]].massa;
				cout << endl;
				break;
			case 6:
				if (vetorDinamicoAvioes[cartasJogador1[x]].quantidadeMotores > vetorDinamicoAvioes[cartasJogador2[x]].preco)
					pontosJogador1 += 2;
				else if ((vetorDinamicoAvioes[cartasJogador1[x]].quantidadeMotores < vetorDinamicoAvioes[cartasJogador2[x]].preco))
					pontosJogador2 += 2;
				else
				{
					pontosJogador1 += 1;
					pontosJogador2 += 1;
				}

				cout << "[" << jogador1 << "] " << vetorDinamicoAvioes[cartasJogador1[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador1[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador1[x]].quantidadeMotores;
				cout << "[" << jogador2 << "] " << vetorDinamicoAvioes[cartasJogador2[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador2[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador2[x]].quantidadeMotores;
				cout << endl;
				break;
			case 7:
				if (vetorDinamicoAvioes[cartasJogador1[x]].velocidadeMaxima > vetorDinamicoAvioes[cartasJogador2[x]].velocidadeMaxima)
					pontosJogador1 += 2;
				else if ((vetorDinamicoAvioes[cartasJogador1[x]].velocidadeMaxima < vetorDinamicoAvioes[cartasJogador2[x]].velocidadeMaxima))
					pontosJogador2 += 2;
				else
				{
					pontosJogador1 += 1;
					pontosJogador2 += 1;
				}

				cout << "[" << jogador1 << "] " << vetorDinamicoAvioes[cartasJogador1[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador1[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador1[x]].velocidadeMaxima;
				cout << "[" << jogador2 << "] " << vetorDinamicoAvioes[cartasJogador2[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador2[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador2[x]].velocidadeMaxima;
				cout << endl;
				break;
			case 8:
				if (vetorDinamicoAvioes[cartasJogador1[x]].velocidadeCruzeiro > vetorDinamicoAvioes[cartasJogador2[x]].velocidadeCruzeiro)
					pontosJogador1 += 2;
				else if ((vetorDinamicoAvioes[cartasJogador1[x]].velocidadeCruzeiro < vetorDinamicoAvioes[cartasJogador2[x]].velocidadeCruzeiro))
					pontosJogador2 += 2;
				else
				{
					pontosJogador1 += 1;
					pontosJogador2 += 1;
				}

				cout << "[" << jogador1 << "] " << vetorDinamicoAvioes[cartasJogador1[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador1[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador1[x]].velocidadeCruzeiro;
				cout << "[" << jogador2 << "] " << vetorDinamicoAvioes[cartasJogador2[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador2[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador2[x]].velocidadeCruzeiro;
				cout << endl;
				break;
			case 9:
				if (vetorDinamicoAvioes[cartasJogador1[x]].alcance > vetorDinamicoAvioes[cartasJogador2[x]].alcance)
					pontosJogador1 += 2;
				else if ((vetorDinamicoAvioes[cartasJogador1[x]].alcance < vetorDinamicoAvioes[cartasJogador2[x]].alcance))
					pontosJogador2 += 2;
				else
				{
					pontosJogador1 += 1;
					pontosJogador2 += 1;
				}

				cout << "[" << jogador1 << "] " << vetorDinamicoAvioes[cartasJogador1[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador1[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador1[x]].alcance;
				cout << "[" << jogador2 << "] " << vetorDinamicoAvioes[cartasJogador2[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador2[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador2[x]].alcance;
				cout << endl;
				break;
			case 10:
				if (vetorDinamicoAvioes[cartasJogador1[x]].tetoMaximo > vetorDinamicoAvioes[cartasJogador2[x]].tetoMaximo)
					pontosJogador1 += 2;
				else if ((vetorDinamicoAvioes[cartasJogador1[x]].tetoMaximo < vetorDinamicoAvioes[cartasJogador2[x]].tetoMaximo))
					pontosJogador2 += 2;
				else
				{
					pontosJogador1 += 1;
					pontosJogador2 += 1;
				}

				cout << "[" << jogador1 << "] " << vetorDinamicoAvioes[cartasJogador1[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador1[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador1[x]].tetoMaximo;
				cout << "[" << jogador2 << "] " << vetorDinamicoAvioes[cartasJogador2[x]].fabricante << " " << vetorDinamicoAvioes[cartasJogador2[x]].modelo;
				cout << " " << vetorDinamicoAvioes[cartasJogador2[x]].tetoMaximo;
				cout << endl;
			}

			if (rodada < 4) //Placar atual de cada rodada. Caso seja a última, aparece só o placar final
				cout << "Placar: " << jogador1 << " " << pontosJogador1 << " " << " X " << " " << pontosJogador2 << " " << jogador2 << endl;
			
			rodada += 1; //Incremento da rodada
		}

		cout << endl;
		cout << "Final: " << jogador1 << " X " << jogador2 << endl; //Placar final
		cout << endl;

		cout << "Iniciar nova partida? [S/N] "; //Pedido para nova partida
		cin >> novoJogo;
	}

	delete[] vetorDinamicoAvioes; //Apaga vetor dinâmico

	system("pause");
	return 0;
}