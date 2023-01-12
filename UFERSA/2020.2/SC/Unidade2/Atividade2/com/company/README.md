Aleff Jonathan da Silva Soares de Souza
Vitor Oliveira Ropke

Vídeo da gravação:	

https://drive.google.com/file/d/1zBGUEWg4NfplZ0fDIRWBzUnhrPKNijRY/view

ou

https://youtu.be/s_wMoPzn60U


UNIVERSIDADE FEDERAL RURAL DO SEMIÁRIDO - UFERSA
Departamento de Computação - DC
Graduação em Ciência da Computação
Disciplina: Segurança Computacional
Prof.: Paulo Henrique Lopes Silva 
Atividade 2 – Unidade 2
Projeto 2
1. Descrição geral
O objetivo do projeto é o desenvolvimento de um sistema que utilize a cifra assimétrica RSA
para garantir a confidencialidade das comunicações entre um emissor (cliente de um banco) e um
receptor (banco ou agência virtual).   
2. User Stories
User Stories são uma forma de expressar requisitos funcionais desejados para o sistema (o
que o sistema deve fazer). Elas focam nos objetivos dos usuários e como eles conseguem alcançá-
los. User stories devem ser curtas, simples e escritas sob o ponto de vista do usuário. Observe que,
no mundo real, o cliente poderá mudar de ideia com respeito a esses requisitos funcionais.
User Story Título Descrição
1. Autenticação Clientes do banco devem acessar o sistema por
meio  de  autenticação  usando  o  número  da
conta e a senha.  
2. Criar conta corrente Cada conta possui, no mínimo, atributos como:
cpf,   nome   do   cliente,   endereço,   data   de
nascimento e telefone. 
3. Saque Cada  cliente  pode  sacar  algum  valor  de  sua
conta, desde que a mesma não esteja vazia. 
4. Depósito Cada cliente pode depositar algum valor na sua
conta.  
5. Transferência Clientes podem transferir valores entre contas
(correntes) do banco.
6. Saldo Retorna o valor corrente contido na conta.
7. Investimentos Poupança   (criada   automaticamente   na
criação  da  conta  corrente):  rende  0,5%  ao
mês. 
Renda fixa (o correntista escolhe investir na
renda fixa): rende 1,5% ao mês.
Cada investimento deve ter uma tela única que
mostrará o valor aplicado e uma simulação de
rendimento para três, seis e doze meses.  

3. Detalhamento dos Requisitos.
• O Projeto 2 depende das funcionalidades implementadas no Projeto 1.  
• O  banco  deve  garantir  que  todas  as  comunicações  com  clientes  (ida  e  volta)  sejam
criptografadas usando RSA.
◦ Para cada cliente, uma conexão deve ser criada. A ação de se conectar deve gerar um par
de chaves específico.
• Três contas devem estar criadas no início do programa.
• Sugere-se utilizar:
◦ Chaves pequenas: 16 ou 32 bits.
◦ O sistema de codificação ASCII. Caso outro seja utilizado, mencione.
• Invariantes podem surgir: a codificação de um caractere gerar o mesmo código em plain
text.
• Sobre a divisão de blocos para a codificação:
◦ Recomenda-se tomar cuidado para nenhum caractere possua um código numérico maior
que o módulo (n = p * q) calculado no RSA.
◦ Nenhum bloco deve começar com zero. Ver um exemplo disso na aula sobre RSA.
4. Observações.
• O prazo para a entrega dos projetos expira em 19/05/2021 às 23:59h, via SIGAA. Portanto,
certifiquem-se do arquivo que vão enviar.
• Avaliação: o projeto vale 60% da nota da 2a unidade.
◦ Metade para o código rodando corretamente.
◦ Metade para perguntas individuais sobre o código.   
• Para os que enviarem por e-mail, depois do prazo, o projeto valerá 20% a menos.
• O projeto pode ser desenvolvido de forma individual ou em dupla.   
• Utilize preferencialmente a linguagem Java para o desenvolvimento do trabalho. 
• A correção será realizada em sala por meio da observação e análise do funcionamento das
aplicações.  Os  (As)  integrantes  de  cada  projeto  devem  estar  preparados  para  perguntas
individuais durante a apresentação. 
• Sabe-se que a estrutura de projetos dessa natureza pode ser muito comum. No entanto, a
lógica de funcionamento, o armazenamento e a visualização das informações da loja podem
ser bem particulares. Cuidado com códigos iguais. A penalidade é a nota ZERO.  


UNIVERSIDADE FEDERAL RURAL DO SEMIÁRIDO - UFERSA
Departamento de Computação - DC
Graduação em Ciência da Computação
Disciplina: Segurança Computacional
Prof.: Paulo Henrique Lopes Silva 
Prova 2 - Parte 2
Roteiro para Gravação da Apresentação
1. Executar o programa resultante de cada enunciado, questão ou projeto.
2. Para cada programa, execute uma operação por vez.
• Durante a testagem de cada funcionalidade comente sobre os possíveis erros e exceções que 
podem ocorrer mediante entradas incorretas. Comente também sobre quais erros e exceções 
seu programa captura.
• Cite as ferramentas e tecnologias utilizadas.
• Seu programa implementa todas as funcionalidades requeridas?
3. Após a demonstração de funcionamento, é hora de abrir o código. 
• Explique: 
◦ Como o algoritmo RSA foi implementado.
• Houve alguma dificuldade ou detalhe interessante na implementação de algum dos 
requisitos mencionados (item 3 da atividade)?
• Quais as principais dificuldades e lições aprendidas com o desenvolvimento do projeto?
4. Responda as perguntas detalhando o código que você implementou.
5. Detalhamento das instruções:
• O vídeo deve ter no máximo 20 minutos.
• A gravação será o instrumento avaliativo.
◦ Se o trabalho foi feito em grupo, é importante dividir igualmente o tempo em que cada 
componente apresenta.
• Pontos de avaliação:
◦ Sequência lógica e domínio do conteúdo (introdução, divisão organizada da 
apresentação, concatenação de ideias e conclusão).
◦ Precisão na comunicação (colocação e entonação da voz, ritmo, dicção e linguagem).
◦ Capacidade de argumentação.
◦ Domínio e uso de material (organização no uso de recursos de apresentação).
6. Sugestões de software para gravação:
• Google Meet, Zoom, SimpleScreenRecorder, OBS, etc.
