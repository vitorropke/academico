Aleff Jonathan da Silva Soares de Souza

Vitor Oliveira Ropke

Página
1
/2
Página 1 de 2

UNIVERSIDADE FEDERAL RURAL DO SEMIÁRIDO - UFERSA

Departamento de Computação - DC

Graduação em Ciência da Computação

Disciplina: Segurança Computacional

Prof.: Paulo Henrique Lopes Silva

Projeto 1 (Atividade 3)

1. Descrição geral

O objetivo do projeto é o desenvolvimento de um sistema que utilize cifras simétricas para

garantir a confidencialidade das comunicações entre um emissor (cliente de um banco) e um

receptor (banco ou agência virtual).

2. User Stories

User Stories são uma forma de expressar requisitos funcionais desejados para o sistema (o

que o sistema deve fazer). Elas focam nos objetivos dos usuários e como eles conseguem alcançá- los. User stories devem ser curtas, simples e escritas sob o ponto de vista do usuário. Observe que,

no mundo real, o cliente poderá mudar de ideia com respeito a esses requisitos funcionais.

User Story Título Descrição

1. Autenticação

Clientes do banco devem acessar o sistema por

meio de autenticação usando o número da

conta e a senha.

2. Criar conta corrente

Cada conta possui, no mínimo, atributos como:

cpf, nome do cliente, endereço, data de

nascimento e telefone.

3. Saque Cada cliente pode sacar algum valor de sua

conta, desde que a mesma não esteja vazia.

4. Depósito Cada cliente pode depositar algum valor na sua

conta.

5. Transferência Clientes podem transferir valores entre contas

(correntes) do banco.

6. Saldo Retorna o valor corrente contido na conta.

7. Investimentos

Poupança (criada automaticamente na

criação da conta corrente): rende 0,5% ao

mês.

Renda fixa (o correntista escolhe investir na

renda fixa): rende 1,5% ao mês.

Cada investimento deve ter uma tela única que

mostrará o valor aplicado e uma simulação de

rendimento para três, seis e doze meses.
Página 1 de 2
Página 2 de 2

3. Detalhamento dos Requisitos.

• O sistema constitui-se de emissores e receptores de mensagens.

◦ Exemplo: clientes são emissores e o banco (agência virtual) é o receptor

• As mensagens enviadas de emissores a receptores devem ser cifradas usando algoritmos

simétricos. Os algoritmos que devem ser implementados são:

◦ Cifra de César (10%).

◦ Cifra de Vigenère (15%).

◦ Cifra de Vernam (15%).

• Emissor encripta a mensagem com um algoritmo em envia. Receptor decripta a mensagem e

realiza a operação solicitada.

• Três contas devem estar criadas no início do programa.

4. Nessa atividade, pede-se também:

• Implementação do processo de expansão (ou escalonamento) de chaves do algoritmo AES.

◦ Implementar o processo para chaves de 128, 192 e 256 bits.

◦ A entrada do programa deve ser uma chave (inteiro, hexadecimal ou string) em cada um

dos tamanhos solicitados.

◦ O programa deve mostrar (inteiro, hexadecimal ou string):

▪ as 44 subchaves para a chave de entrada de 128 bits.

▪ as 52 subchaves para a chave de entrada de 192 bits.

▪ as 60 subchaves par a chave de entrada de 256 bits.

◦ Link para consulta (contendo todo o processo de expansão): encurtador.com.br/wyEY3

◦ Essa parte da atividade vale 30%.

5. Observações.

• O prazo para a entrega dos projetos expira em 07/04/2021 às 23:59h, via SIGAA. Portanto,

certifiquem-se do arquivo que vão enviar.

• O trabalho pode se feito em dupla ou individual.

• Avaliação: o projeto vale 70% da nota da 1a

unidade.

◦ Metade para o código rodando corretamente.

◦ Metade para perguntas individuais sobre o código.

• Para os que enviarem por e-mail, depois do prazo, o projeto valerá 30% a menos.

• O projeto pode ser desenvolvido de forma individual ou em dupla.

• Utilize preferencialmente a linguagem Java para o desenvolvimento do trabalho.

• A correção será realizada em sala por meio da observação e análise do funcionamento das

aplicações. Os(As) integrantes de cada projeto devem estar preparados para perguntas

individuais durante a apresentação.

• Sabe-se que a estrutura de projetos dessa natureza pode ser muito comum. No entanto, a

lógica de funcionamento, o armazenamento e a visualização das informações da loja podem

ser bem particulares. Cuidado com códigos iguais. A penalidade é a nota ZERO.
Página 2 de 2
atividade3.pdf
Exibindo atividade3.pdf… Página 1 de 2
