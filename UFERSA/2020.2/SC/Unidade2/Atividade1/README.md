UNIVERSIDADE FEDERAL RURAL DO SEMIÁRIDO - UFERSA
Departamento de Computação - DC
Graduação em Ciência da Computação
Disciplina: Segurança Computacional
Prof.: Paulo Henrique Lopes Silva 
Atividade 1 – Unidade 2
Autenticação de mensagens e funções de hash
1. Suponha que Alice deseja enviar mensagens seguras para Bob. Considere APUB e APRI
, as chaves
pública  e  privada  de Alice,  respectivamente;  similarmente  para  Bob  (BPUB  e  BPRI).  Considere
também que Mallory conhece as chaves públicas de A e B, porém não conhece as suas chaves
privadas respectivas.
1. Mallory pode enviar mensagens confidenciais para Alice? Justifique.
2. Mallory pode verificar a assinatura digital de uma mensagem enviada por Bob? Justifique.
3. Explique como Alice pode obter confidencialidade e autenticidade nas mensagens que envia
para Bob.
2. Quando uma combinação de criptografia simétrica e um código de controle de erros são usados
para a autenticação de mensagens, em que ordem as duas funções precisam ser realizadas?
3.  Qual   é  a  diferença  entre  um  código  de  autenticação  de  mensagens  e  uma  função  hash
unidirecional?
4. Em que ordem a função de assinatura digital e a função de confidencialidade devem ser aplicadas
a uma mensagem? Por que?
5. É necessário recuperar a chave secreta a fim de atacar um algoritmo MAC? Justifique.
6. Pesquise e elabore uma resposta expositiva sobre as características, modo de funcionamento,
vantagens e desvantagens entre os algoritmos:
1. SHA-2 e SHA-3.
2. CMAC e HMAC.
Certificados digitais 
7. Você tem uma cópia da cadeia de certificados de Bob: seu certificado é assinado pela AC EECS;
o certificado do EECS é assinado pela AC UC Berkeley; o certificado da UC Berkeley é assinado
pela Verisign. Quais chaves públicas você precisa para validar a chave pública de Bob?
8.  Suponha  que um  sistema utilize  a  infraestrutura  de  chaves públicas  (PKI) baseada  em uma

hierarquia estruturada em árvore de ACs. Alice quer se comunicar com Bob e recebe um certificado
de Bob assinado por uma AC X, depois de estabelecer um canal de comunicação com Bob. Suponha
que Alice nunca tenha ouvido falar em X. Que etapas Alice deve executar para confirmar que está
se comunicando com Bob?
9. Com base nos dados (resultado da exportação de um certificado digital) a seguir, determine:
a) Nome da Autoridade Certificadora de assinatura.
b) Tipo (simétrico ou assimétrico? Qual algoritmo?) e tamanho da chave de criptografia do
dono do certificado digital.
c) Algoritmo hash utilizado e tamanho do código de resumo de mensagem gerado.
d) Cite e descreva os passos envolvidos para a criação de um certificado digital.
e) Explique    o  processo  no  qual   um  usuário  pode  validar  (verificar  a  assinatura)  esse
certificado digital.
Nome do portador
C (País): US
O (Organização): VeriSign, Inc.
OU (Unidade organizacional): VeriSign Trust Network
OU (Unidade organizacional): (c) 2008 VeriSign, Inc. - For authorized use only
CN (Nome completo): VeriSign Universal Root Certification Authority
Nome do emissor
C (País): US
O (Organização): VeriSign, Inc.
OU (Unidade organizacional): VeriSign Trust Network
OU (Unidade organizacional): (c) 2008 VeriSign, Inc. - For authorized use only
CN (Nome completo): VeriSign Universal Root Certification Authority
Certificado emitido
Versão:3
Número de série: 40 1A C4 64 21 B3 13 21 03 0E BB E4 12 1A C5 1D
Não é válido antes de: 2008-04-02
Não é válido após: 2037-12-01
Impressões digitais do certificado
SHA1: 36 79 CA 35 66 87 72 30 4D 30 A5 FB 87 3B 0F A7 7B B7 0D 54
MD5: 8E AD B5 01 AA 4D 81 E4 8C 1D D1 E1 14 00 95 19
Informações da chave pública
Algoritmo da chave: RSA
Parâmetros da chave: 05 00
Tamanho da chave: 2048
Impressão digital SHA1 da chave: BB C2 3E 29 0B B3 28 77 1D AD 3E A2 4D BD F4 23 BD 06 B0 3D
Chave pública: 30 82 01 0A 02 82 01 01 00 C7 61 37 5E B1 01 34 DB 62 D7 15 9B FF 58 5A 8C 23 23 D6
60 8E 91 D7 90 98 83 7A E6 58 19 38 8C C5 F6 E5 64 85 B4 A2 71 FB ED BD B9 DA CD 4D 00 B4 C8 2D
73 A5 C7 69 71 95 1F 39 3C B2 44 07 9C E8 0E FA 4D 4A C4 21 DF 29 61 8F 32 22 61 82 C5 87 1F 6E
8C 7C 5F 16 20 51 44 D1 70 4F 57 EA E3 1C E3 CC 79 EE 58 D8 0E C2 B3 45 93 C0 2C E7 9A 17 2B 7B
00 37 7A 41 33 78 E1 33 E2 F3 10 1A 7F 87 2C BE F6 F5 F7 42 E2 E5 BF 87 62 89 5F 00 4B DF C5 DD
E4 75 44 32 41 3A 1E 71 6E 69 CB 0B 75 46 08 D1 CA D2 2B 95 D0 CF FB B9 40 6B 64 8C 57 4D FC 13
11 79 84 ED 5E 54 F6 34 9F 08 01 F3 10 25 06 17 4A DA F1 1D 7A 66 6B 98 60 66 A4 D9 EF D2 2E 82 F1
F0 EF 09 EA 44 C9 15 6A E2 03 6E 33 D3 AC 9F 55 00 C7 F6 08 6A 94 B9 5F DC E0 33 F1 84 60 F9 5B
27 11 B4 FC 16 F2 BB 56 6A 80 25 8D 02 03 01 00 01
Restrições básicas
Autoridade do certificado: Sim
Comp máx do caminho:Ilimitado
Crítico: Sim
Uso da chave
Usos: Assinatura digital
Crítico: Sim
Ramal
Identificador: 1.3.6.1.5.5.7.1.12

Valor: 30 5F A1 5D A0 5B 30 59 30 57 30 55 16 09 69 6D 61 67 65 2F 67 69 66 30 21 30 1F 30 07 06 05
2B 0E 03 02 1A 04 14 8F E5 D3 1A 86 AC 8D 8E 6B C3 CF 80 6A D4 48 18 2C 7B 19 2E 30 25 16 23 68
74 74 70 3A 2F 2F 6C 6F 67 6F 2E 76 65 72 69 73 69 67 6E 2E 63 6F 6D 2F 76 73 6C 6F 67 6F 2E 67 69
66
Crítico: Não
Identificador da chave do sujeito
Identificador da chave: B6 77 FA 69 48 47 9F 53 12 D5 C2 EA 07 32 76 07 D1 97 07 19
Crítico: Não
Assinatura
Algoritmo da assinatura: 1.2.840.113549.1.1.11
Parâmetros da assinatura: 05 00
Assinatura: 4A F8 F8 B0 03 E6 2C 67 7B E4 94 77 63 CC 6E 4C F9 7D 0E 0D DC C8 B9 35 B9 70 4F
63 FA 24 FA 6C 83 8C 47 9D 3B 63 F3 9A F9 76 32 95 91 B1 77 BC AC 9A BE B1 E4 31 21 C6 81 95 56
5A 0E B1 C2 D4 B1 A6 59 AC F1 63 CB B8 4C 1D 59 90 4A EF 90 16 28 1F 5A AE 10 FB 81 50 38 0C 6C
CC F1 3D C3 F5 63 E3 B3 E3 21 C9 24 39 E9 FD 15 66 46 F4 1B 11 D0 4D 73 A3 7D 46 F9 3D ED A8 5F
62 D4 F1 3F F8 E0 74 57 2B 18 9D 81 B4 C4 28 DA 94 97 A5 70 EB AC 1D BE 07 11 F0 D5 DB DD E5 8C
F0 D5 32 B0 83 E6 57 E2 8F BF BE A1 AA BF 3D 1D B5 D4 38 EA D7 B0 5C 3A 4F 6A 3F 8F C0 66 6C 63
AA E9 D9 A4 16 F4 81 D1 95 14 0E 7D CD 95 34 D9 D2 8F 70 73 81 7B 9C 7E BD 98 61 D8 45 87 98 90
C5 EB 86 30 C6 35 BF F0 FF C3 55 88 83 4B EF 05 92 06 71 F2 B8 98 93 B7 EC CD 82 61 F1 38 E6 4F
97 98 2A 5A 8D
10. Alice quer se comunicar com Bob usando a criptografia de chave pública. Ela estabelece uma
conexão com alguém e espera que seja Bob. Alice pede a ele sua chave pública e ele a envia, em
texto simples, juntamente com um certificado X.509 assinado pela AC raiz. Alice já tem a chave
pública da AC raiz. Que etapas ela deve executar para verificar se está se comunicando com Bob?
Suponha que Bob não se importe em saber com quem está se comunicando.
Observações.
• Avaliação: a atividade 1 vale 4,0 pontos na nota da unidade 2.
• Prazo de  entrega:  07/05/2021  até as  23h59. Portanto,  certifiquem-se do  arquivo que vão
enviar.
◦ Crie uma pasta chamada “seu-nome-seg-atividade1-u2”, comprima e envie pelo SIGAA
ou Google Classroom.
• Envio por e-mail, depois do prazo, acarreta a diminuição da nota da atividade em 20%.
• A atividade é individual. Cada discente deve elaborar a sua resposta. Cuidado com respostas
iguais. A penalidade é a nota ZERO.
