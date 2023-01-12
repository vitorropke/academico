UNIVERSIDADE FEDERAL RURAL DO SEMIÁRIDO - UFERSA
Departamento de Computação - DC
Graduação em Ciência da Computação
Disciplina: Segurança Computacional
Prof.: Paulo Henrique Lopes Silva 
Atividade 1
1. Relacione pelo menos três riscos  de  segurança  que podem  surgir  quando  alguém tem  o  se
computador portátil roubado 2. Há alguma situação em que a confidencialidade de dados é mais importante que a sua integrida
e a disponibilidade? Justifique a sua resposta.
3. Suponha que o autor de um sistema de software de banco online programou uma característic
secreta que faz o programa enviar para ele informação sobre qualquer conta cujo saldo ultrapasse
10.000. Qual é o tipo de ataque: ativo ou passivo? Justifique
4.  O  computador portátil  de  Bob  foi recém infectado po r algu m software malicios o que us a
câmera embutida no computador para gravar um vídeo cada vez que ele sente um movimento
depois coloca esse vídeo em um popular site de compartilhamento de vídeos. Qual tipo de ataq
isso envolve e quais conceitos de segurança ele viola? 
5. Um possíveltécnica contra remoção acidental de software é salvar/armazenar todas as versõ
anteriores. Esta técnica tem um custo relativamente alto de armazenamento. Sugira outra técnica 
menor  custo  contra  remoção  acidental  de  software. A  técnica  que  você  apresentou  e ́ efetiv
Justifique a sua resposta.
6.  Considere  um  sistema  no  qual   existe  um  conjunto  de  informações  disponíveis  para  u
determinado grupo de usuários denominado “desenvolvedores”, com acessos de leitura e escrita
Após  várias  operações  realizadas  com  sucesso ,  em  um  determinado  momento ,  um  usuár
pertencente ao grupo “desenvolvedores” acessa o sistema em busca de uma informação e recebe,
como resposta à sua consulta, uma informação errada. Neste caso, houve falha na segurança para o
sistema com relação a qual(is) serviço(s) de segurança? Justifique. 7. Considere a descrição de um ataque, a seguir, e responda às questões. 
“Quando um cliente tenta começar uma conexão TCP com um servidor, ambos trocam uma série
de mensagens, que  normalmente são assim: o cliente requisita  uma conexão enviando  um SYN
(synchronize)   ao  servidor;   o  servidor   confirma  esta  requisição  mandando  um  SYN-ACK
(acknowledge) de volta ao cliente e o cliente por sua vez responde com um ACK, e a conexão está
estabelecida. Isto é o chamado aperto de mão em três etapas (Three-Way Handshake). Um cliente
malicioso, que  implemente  intencionalmente  um protocolo  TCP errado e  incompleto, pode  não
mandar esta última mensagem ACK. O servidor  irá esperar por  isso por um tempo, já que um
simples congestionamento de rede pode ser a causa do ACK faltante. Esta chamada conexão semi-
aberta explora a boa-fé do protocolo TCP que espera por um certo tempo e algumas tentativas de
restabelecimento de um sinal ACK válido para retomar a comunicação. A resposta maliciosa ao
comando SYN gerada pelo cliente pode ocupar recursos no servidor (memória e processamento) ou
causar prej uízos para empresas usando softwares licenciados por conexão (aumento de conexões
"ativas"). Pode ser possível ocupar todos os recursos da máquina, com pacotes SYN. Uma vez que
todos os recursos estejam ocupados, nenhuma nova conexão (legítima ou não) pode ser feita”.
• Quais  serviço(s)  de  segurança  foi(foram)  diretamente  comprometido(s)? Justifique  a  sua
resposta.
• Que medidas (mecanismos de segurança) proativas podem ser tomadas para o ataque não
ocorrer? 
8. É correta a seguinte afirmação? É muito difícil impedir ataques ativos devido à grande variedad
de vulnerabilidades  físicas,  de  software  e  de  rede  em  potencial.  Sendo  assim,  recomenda-se  
detecção ataques ativos, seguida de recuperação em caso de interrupção ou atrasos causados por
eles. Justifique.
Observações.
• Avaliação: a atividade 1 vale 1,0 ponto na nota da unidade 1.
• Envio por e-mail, depois do prazo, acarreta a diminuição da nota da atividade em 30%.
• A atividade é individual. Cada discente deve elaborar a sua resposta. Cuidado com resposta
iguais. A penalidade é a nota ZERO
• Prazo de entrega: 19/03/2021.  


UNIVERSIDADE FEDERAL RURAL DO SEMIÁRIDO - UFERSA
Departamento de Computação - DC
Graduação em Ciência da Computação
Disciplina: Segurança Computacional
Prof.: Paulo Henrique Lopes Silva
Atividade 2: Investigando Requisitos de Segurança
Descrição
Alice e Bob são auditores de segurança da informação e, ao efetuarem suas atividades na Mega
Corporation, se depararam com os seguintes problemas de segurança:
1. Maria transmitiu um arquivo para o João. O arquivo contém informações confidenciais (por
exemplo, registros da folha de pagamentos da empresa) que devem ser protegidas contra
divulgação não-autorizada. Porém, Alice e Bob observaram que José, usuário não está
autorizado a fazer a leitura desse arquivo, monitorou a transmissão do arquivo e ainda
obteve uma cópia do arquivo durante essa transmissão;
2. Um dos gerentes da rede de comunicação da empresa, Ana, transmitiu uma mensagem a um
computador X, sob seu gerenciamento. A mensagem instruía o computador X a utilizar um
arquivo de autorização para incluir as identidades de diversos novos usuários que deveriam
receber acesso a esse computador. O usuário Joaquim interceptou a mensagem, alterou o seu
conteúdo para incluir ou excluir entradas e, depois, encaminhou a mensagem para X, que
por sua vez, aceitou a mensagem como se tivesse vindo da Ana e atualizou o seu arquivo de
autorização conforme solicitado.
Produto
Sendo assim, vocês são convidados a auxiliar Alice e Bob com o seguinte produto: Relatório
contendo, para cada descrição de ataque, uma justificativa de qual tipo de ataque foi efetuado e qual
(ou quais) requisito(s) de segurança foram diretamente comprometidos.
Observações.
•
•
•
•
Avaliação: a atividade 1 vale 1,0 ponto na nota da unidade 1.
Envio por e-mail, depois do prazo, acarreta a diminuição da nota da atividade em 30%.
A atividade é individual. Cada discente deve elaborar a sua resposta. Cuidado com respostas
iguais. A penalidade é a nota ZERO.
Prazo de entrega: 19/03/2021.
