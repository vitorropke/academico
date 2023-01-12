import java.math.BigInteger;

public class Aes {
	static final int[] tabelaRCON =	{
											0x00000000, 0x01000000, 0x02000000, 0x04000000,
											0x08000000, 0x10000000, 0x20000000, 0x40000000,
											0x80000000, 0x1b000000, 0x36000000
										};
	// https://github.com/alexkiro/AES/blob/master/src/aes/SBox.java
	static final int[][] sBox =	{
									{ 0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76 },
									{ 0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0 },
									{ 0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15 },
									{ 0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75 },
									{ 0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84 },
									{ 0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf },
									{ 0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8 },
									{ 0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2 },
									{ 0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73 },
									{ 0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb },
									{ 0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79 },
									{ 0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08 },
									{ 0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a },
									{ 0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e },
									{ 0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf },
									{ 0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 }
								};

	public static String[] expandirChave(String chave) {
		int			tamanhoChave = chave.length();
		String[]	chaves = null;					// vetor que será retornado pela função

		// verifica se a chave possui 128 bits (16 caracteres), 192 bits (24 caracteres) ou 256 bits (32 caracteres)
		if (tamanhoChave != 16 && tamanhoChave != 24 && tamanhoChave != 32) {
			System.out.println("Falha na encriptacao. Chave possui tamanho inválido.");
			String[] vazio = { "" };
			return vazio;
		}

		int numeroPalavras;
		// 128 bits
		if (tamanhoChave == 16) {
			String hexChave;			// contém o formato hexadecimal da chave
			chaves = new String[44];	// 44 subchaves
			numeroPalavras = 4;

			// string para hex
			// "%032x" significa que a string hexadecimal terá 32 caracteres
			hexChave = String.format("%032x", new BigInteger(1, chave.getBytes()));
			//hexChave = "2b7e151628aed2a6abf7158809cf4f3c";
			System.out.print("Chave hexadecimal:   ");
			System.out.println(hexChave);
			
			System.out.println();

			// separa a chave hexadecimal para as subchaves
			chaves[0] = hexChave.substring(0, 8);
			chaves[1] = hexChave.substring(8, 16);
			chaves[2] = hexChave.substring(16, 24);
			chaves[3] = hexChave.substring(24, 32);

			String	rotWordChave;			// desloca os dois primeiros caracteres para o final da string
			String	stringResultadoSBox;	// resultado da chave usando S-Box
			String	stringTabelaRCON;
			int		xSBox, ySBox;			// coordenadas da tabela S-Box
			int		indiceInterno;
			long	longResultadoSBox;
			long	xorSBoxRCON;
			long	longChave;
			long	xorChaveRCONSubWord;
			long	longTabelaRCON;

			for (int i = 4; i < 44; i++) {
				// RotWord-------------------------------------------------------------------------------------------
				rotWordChave = chaves[i - 1].substring(2, 8) + chaves[i - 1].substring(0, 2);

				// SubWord-------------------------------------------------------------------------------------------
				stringResultadoSBox = "";
				
				// converte o caractere para o valor inteiro correspondente
				// 'a' = 10; 'b' = 11; 'c' = 12; 'd' = 13; 'e' = 14; 'f' = 15
				for (int x = 0; x < 8; x++) {
					xSBox = Character.getNumericValue(rotWordChave.charAt(x));				// pega a linha da tabela S-Box
					x++;
					ySBox = Character.getNumericValue(rotWordChave.charAt(x));				// pega a coluna da tabela S-Box

					stringResultadoSBox += String.format("%02x", Aes.sBox[xSBox][ySBox]);	// pega o valor da tabela S-Box
					// "%02x" fixa a saída para 2 caracteres
				}

				// XOR RCON e SubWord--------------------------------------------------------------------------------
				stringTabelaRCON = String.format("%08x", Aes.tabelaRCON[i / numeroPalavras]);	// int para string
 
				longResultadoSBox = Long.parseLong(stringResultadoSBox, 16);					// string para long
				longTabelaRCON = Long.parseLong(stringTabelaRCON, 16);							// string para long
				xorSBoxRCON = longResultadoSBox ^ longTabelaRCON;								// xor

				// w[i-Nk] e XOR-------------------------------------------------------------------------------------
				// conversao de string para long e xor. Depois long para string
				longChave = Long.parseLong(chaves[i - numeroPalavras], 16);	// string para long
				xorChaveRCONSubWord = longChave ^ xorSBoxRCON;				// xor
				chaves[i] = String.format("%08x", xorChaveRCONSubWord);		// long para string

				for (indiceInterno = 0; indiceInterno < 3; indiceInterno++) {
					i++;

					longChave = Long.parseLong(chaves[i - numeroPalavras], 16);	// string para long
					xorChaveRCONSubWord = longChave ^ xorChaveRCONSubWord;		// xor
					chaves[i] = String.format("%08x", xorChaveRCONSubWord);		// long para string
				}
			}
		// 192 bits
		} else if (tamanhoChave == 24) {
			String hexChave;			// contém o formato hexadecimal da chave
			chaves = new String[52];	// 52 subchaves
			numeroPalavras = 6;

			// string para hex
			// "%048x" significa que a string hexadecimal terá 48 caracteres
			hexChave = String.format("%048x", new BigInteger(1, chave.getBytes()));
			//hexChave = "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b";
			System.out.print("Chave hexadecimal:   ");
			System.out.println(hexChave);
			
			System.out.println();

			// separa a chave hexadecimal para as subchaves
			chaves[0] = hexChave.substring(0, 8);
			chaves[1] = hexChave.substring(8, 16);
			chaves[2] = hexChave.substring(16, 24);
			chaves[3] = hexChave.substring(24, 32);
			chaves[4] = hexChave.substring(32, 40);
			chaves[5] = hexChave.substring(40, 48);

			String	rotWordChave;			// desloca os dois primeiros caracteres para o final da string
			String	stringResultadoSBox;	// resultado da chave usando S-Box
			String	stringTabelaRCON;
			int		xSBox, ySBox;			// coordenadas da tabela S-Box
			int		indiceInterno;
			long	longResultadoSBox;
			long	xorSBoxRCON;
			long	longChave;
			long	xorChaveRCONSubWord;
			long	longTabelaRCON;

			for (int i = 6; i < 52; i++) {
				// RotWord-------------------------------------------------------------------------------------------
				rotWordChave = chaves[i - 1].substring(2, 8) + chaves[i - 1].substring(0, 2);

				// SubWord-------------------------------------------------------------------------------------------
				stringResultadoSBox = "";
				
				// converte o caractere para o valor inteiro correspondente
				// 'a' = 10; 'b' = 11; 'c' = 12; 'd' = 13; 'e' = 14; 'f' = 15
				for (int x = 0; x < 8; x++) {
					xSBox = Character.getNumericValue(rotWordChave.charAt(x));				// pega a linha da tabela S-Box
					x++;
					ySBox = Character.getNumericValue(rotWordChave.charAt(x));				// pega a coluna da tabela S-Box

					stringResultadoSBox += String.format("%02x", Aes.sBox[xSBox][ySBox]);	// pega o valor da tabela S-Box
					// "%02x" fixa a saída para 2 caracteres
				}

				// XOR RCON e SubWord--------------------------------------------------------------------------------
				stringTabelaRCON = String.format("%08x", Aes.tabelaRCON[i / numeroPalavras]);	// int para string
 
				longResultadoSBox = Long.parseLong(stringResultadoSBox, 16);					// string para long
				longTabelaRCON = Long.parseLong(stringTabelaRCON, 16);							// string para long
				xorSBoxRCON = longResultadoSBox ^ longTabelaRCON;								// xor

				// w[i-Nk] e XOR-------------------------------------------------------------------------------------
				// conversao de string para long e xor. Depois long para string
				longChave = Long.parseLong(chaves[i - numeroPalavras], 16);			// string para long
				xorChaveRCONSubWord = longChave ^ xorSBoxRCON;			// xor
				chaves[i] = String.format("%08x", xorChaveRCONSubWord);	// long para string

				// se não for as últimas 4 chaves
				if (i != 48) {
					for (indiceInterno = 0; indiceInterno < 5; indiceInterno++) {
						i++;

						longChave = Long.parseLong(chaves[i - numeroPalavras], 16);	// string para long
						xorChaveRCONSubWord = longChave ^ xorChaveRCONSubWord;		// xor
						chaves[i] = String.format("%08x", xorChaveRCONSubWord);		// long para string
					}
				// se chegar nas últimas 4 chaves
				} else {
					for (indiceInterno = 0; indiceInterno < 3; indiceInterno++) {
						i++;

						longChave = Long.parseLong(chaves[i - numeroPalavras], 16);	// string para long
						xorChaveRCONSubWord = longChave ^ xorChaveRCONSubWord;		// xor 
						chaves[i] = String.format("%08x", xorChaveRCONSubWord);		// long para string
					}
				}
			}
		// 256 bits
		} else {
			String hexChave;			// contém o formato hexadecimal da chave
			chaves = new String[60];	// 60 subchaves
			numeroPalavras = 8;

			// string para hex
			// "%048x" significa que a string hexadecimal terá 48 caracteres
			hexChave = String.format("%064x", new BigInteger(1, chave.getBytes()));
			//hexChave = "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4";
			System.out.print("Chave hexadecimal:   ");
			System.out.println(hexChave);
			
			System.out.println();

			// separa a chave hexadecimal para as subchaves
			chaves[0] = hexChave.substring(0, 8);
			chaves[1] = hexChave.substring(8, 16);
			chaves[2] = hexChave.substring(16, 24);
			chaves[3] = hexChave.substring(24, 32);
			chaves[4] = hexChave.substring(32, 40);
			chaves[5] = hexChave.substring(40, 48);
			chaves[6] = hexChave.substring(48, 56);
			chaves[7] = hexChave.substring(56, 64);

			String	rotWordChave;			// desloca os dois primeiros caracteres para o final da string
			String	stringResultadoSBox;	// resultado da chave usando S-Box
			String	stringTabelaRCON;
			int		xSBox, ySBox;			// coordenadas da tabela S-Box
			int		indiceInterno;
			long	longResultadoSBox;
			long	xorSBoxRCON;
			long	longChave;
			long	xorChaveRCONSubWord;
			long	longTabelaRCON;

			for (int i = 8; i < 59; i++) {
				// RotWord-------------------------------------------------------------------------------------------
				rotWordChave = chaves[i - 1].substring(2, 8) + chaves[i - 1].substring(0, 2);

				// SubWord-------------------------------------------------------------------------------------------
				stringResultadoSBox = "";
				
				// converte o caractere para o valor inteiro correspondente
				// 'a' = 10; 'b' = 11; 'c' = 12; 'd' = 13; 'e' = 14; 'f' = 15
				for (int x = 0; x < 8; x++) {
					xSBox = Character.getNumericValue(rotWordChave.charAt(x));				// pega a linha da tabela S-Box
					x++;
					ySBox = Character.getNumericValue(rotWordChave.charAt(x));				// pega a coluna da tabela S-Box

					stringResultadoSBox += String.format("%02x", Aes.sBox[xSBox][ySBox]);	// pega o valor da tabela S-Box
					// "%02x" fixa a saída para 2 caracteres
				}

				// XOR RCON e SubWord--------------------------------------------------------------------------------
				stringTabelaRCON = String.format("%08x", Aes.tabelaRCON[i / numeroPalavras]);	// int para string
 
				longResultadoSBox = Long.parseLong(stringResultadoSBox, 16);					// string para long
				longTabelaRCON = Long.parseLong(stringTabelaRCON, 16);							// string para long
				xorSBoxRCON = longResultadoSBox ^ longTabelaRCON;								// xor

				// w[i-Nk] e XOR-------------------------------------------------------------------------------------
				// conversao de string para long e xor. Depois long para string
				longChave = Long.parseLong(chaves[i - numeroPalavras], 16);			// string para long
				xorChaveRCONSubWord = longChave ^ xorSBoxRCON;			// xor
				chaves[i] = String.format("%08x", xorChaveRCONSubWord);	// long para string

				// se não for as últimas 4 chaves
				if (i != 56) {
					for (indiceInterno = 0; indiceInterno < 3; indiceInterno++) {
						i++;

						longChave = Long.parseLong(chaves[i - numeroPalavras], 16);	// string para long
						xorChaveRCONSubWord = longChave ^ xorChaveRCONSubWord;		// xor
						chaves[i] = String.format("%08x", xorChaveRCONSubWord);		// long para string
					}

					// SubWord-------------------------------------------------------------------------------------------
					stringResultadoSBox = "";
					
					// converte o caractere para o valor inteiro correspondente
					// 'a' = 10; 'b' = 11; 'c' = 12; 'd' = 13; 'e' = 14; 'f' = 15
					for (int x = 0; x < 8; x++) {
						xSBox = Character.getNumericValue(chaves[i].charAt(x));					// pega a linha da tabela S-Box
						x++;
						ySBox = Character.getNumericValue(chaves[i].charAt(x));					// pega a coluna da tabela S-Box

						stringResultadoSBox += String.format("%02x", Aes.sBox[xSBox][ySBox]);	// pega o valor da tabela S-Box
						// "%02x" fixa a saída para 2 caracteres
					}

					i++;
					longChave = Long.parseLong(chaves[i - numeroPalavras], 16);		// string para long
					longResultadoSBox = Long.parseLong(stringResultadoSBox, 16);	// string para long
					xorChaveRCONSubWord = longChave ^ longResultadoSBox;			// xor
					chaves[i] = String.format("%08x", xorChaveRCONSubWord);			// long para string

					for (indiceInterno = 0; indiceInterno < 3; indiceInterno++) {
						i++;

						longChave = Long.parseLong(chaves[i - numeroPalavras], 16);	// string para long
						xorChaveRCONSubWord = longChave ^ xorChaveRCONSubWord;		// xor
						chaves[i] = String.format("%08x", xorChaveRCONSubWord);		// long para string
					}
				// se chegar nas últimas 4 chaves
				} else {
					for (indiceInterno = 0; indiceInterno < 3; indiceInterno++) {
						i++;

						longChave = Long.parseLong(chaves[i - numeroPalavras], 16);	// string para long
						xorChaveRCONSubWord = longChave ^ xorChaveRCONSubWord;		// xor
						chaves[i] = String.format("%08x", xorChaveRCONSubWord);		// long para string
					}
				}
			}
		}
		
		return chaves;
	}
}
