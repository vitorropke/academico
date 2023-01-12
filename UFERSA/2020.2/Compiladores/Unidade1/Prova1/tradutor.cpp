#include <fstream>
#include <iostream>
#include <string.h> 
#include "error.h"
#include "parser.h"

using namespace std;

// arquivo de entrada
ifstream fin;

// programa pode receber nomes de arquivos
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		// se for digitado '--help'
		if (strcmp(argv[1], "--help") == 0)
		{
			cout << "\nNosso compilador\n";
			cout << "\nPara executar o compilador vá para a pasta onde está o arquivo tradutor.";
			cout << "\nProvavelmente ele estará em Debug. Se não estiver, explore tudo!";
			cout << "\nAbra o CMD nessa pasta e digite ./tradutor nomeDoArquivo.math";
			cout << "\n\nSe aparecer resultado, significa que funcionou. Senão, verifique";
			cout << "\no nome do arquivo, sua localização em relação ao arquivo 'tradutor'";
			cout << "\ne a extensão dele, se é .math ou outra.";
			cout << "\n\n";

			return 0;
		}

		fin.open(argv[1]);
		
		if (!fin.is_open())
		{
			cout << "Falha na abertura do arquivo \'" << argv[1] << "\'.\n";
			cout << "Verifique se o nome está correto, ou se é protegido para leitura.\n";
			exit(EXIT_FAILURE);
		}

		Parser tradutor;
		try
		{
			tradutor.Start();
		}
		catch (SyntaxError err)
		{
			err.What();
		}
		
		cout << endl;
		fin.close();
	}
}
