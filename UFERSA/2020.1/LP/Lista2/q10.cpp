#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	unsigned int tamanhoA = 0, tamanhoB = 0, resultadosubtracao = 0;
	ListNode *headAInicial = headA, *headBInicial = headB; // Cria um valor inicial dos heads

	// Verifica se existe a interseção na cabeça da lista
	if(headA == headB)
		return headA;

	// Obter os tamanhos das litas
	while(headA != NULL) {
		tamanhoA++;
		headA = headA->next;
	}

	while(headB != NULL) {
		tamanhoB++;
		headB = headB->next;
	}

	// Restaura o valor inicial dos heads
	headA = headAInicial;
	headB = headBInicial;

	if(tamanhoA > tamanhoB) { // Verifica qual a maior lista
		resultadosubtracao = tamanhoA - tamanhoB; // Verifica a diferença de tamanho entre elas

		for(unsigned int i = 0; i < resultadosubtracao; i++) { // Avança a maior lista, para coincidir com a outra
			headA = headA->next;
		}

		while(headA != NULL) { // Procura pela intersecção
			if(headA == headB)
				return headA;

			headA = headA->next;
			headB = headB->next;
		}
	} else {
		resultadosubtracao = tamanhoB - tamanhoA;

		for(unsigned int i = 0; i < resultadosubtracao; i++) { // Avança a maior lista, para coincidir com a outra
			headB = headB->next;
		}

		while(headB != NULL) { // Procura pela intersecção
			if(headA == headB)
				return headB;

			headA = headA->next;
			headB = headB->next;
		}
	}

	return NULL;
}

/* Given a reference (pointer to pointer)
to the head of a list and an int, inserts
a new node on the front of the list. */
void push(ListNode** head_ref, int new_data)
{
	/* 1. allocate node */
	ListNode* new_node = new ListNode(0);

	/* 2. put in the data */
	new_node->val = new_data;

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}

// This function prints contents of
// linked list starting from head
void printList(ListNode *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->val;
		node = node->next;
	}
}

int main() {
	// Inicializa a lista
	ListNode* newNode;

	// Addition of new nodes
	ListNode* head1 = new ListNode(1);
	head1->val = 10;

	ListNode* head2 = new ListNode(1);
	head2->val = 3;

	newNode = new ListNode(1);
	newNode->val = 6;
	head2->next = newNode;

	newNode = new ListNode(1);
	newNode->val = 9;
	head2->next->next = newNode;

	newNode = new ListNode(1);
	newNode->val = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = new ListNode(1);
	newNode->val = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	printList(head1);

	cout << '\n';

	printList(head2);

	cout << '\n';

	cout << getIntersectionNode(head1, head2)->val;

	return 0;
}
