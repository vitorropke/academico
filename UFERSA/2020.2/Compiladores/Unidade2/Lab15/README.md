numtext.l

	Linha 11: [+-]?(([0-9]*(\.)?[0-9]+)([eE][-+]?[0-9]*)?)  cout << "número\n";

wordcount.l

		Linha 7: unsigned charCount = 0, wordCount = 0, lineCount = 0, inputWordCount = 0;
	Add	Linha 8: string inputWord;
		Linha 18: {word}	{ wordCount++; charCount += YYLeng();
	Add	Linha 19 a 24:
								if (YYText() == inputWord)
								{
									inputWordCount++;
								}
							}

	Add	Linha 51 a 61:

		if (argc == 3)
		{
			inputWord = argv[2];

			lexer.yylex();

			cout << "Existem " << inputWordCount << " ocorrências da palavra \"" << argv[2] << "\" no arquivo.\n";

			fin.close();
			return 0;
		}

states.l

	Add	Linha 22: ^[ \t]*"//".*\n 			comments++;                 // linha apenas com comentário 
	Add	Linha 33: <COMMENT>.*"*/".+\n			BEGIN INITIAL; code++;      // fim de linha de comentário e código
