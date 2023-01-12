#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

bool isPalindrome(ListNode* head) {
	string s = "";

	// Coloca a lista em uma string
	while(head != NULL) {
		s += to_string(head->val);

		// Avança para o próximo valor da lista
		head = head->next;
	}

	string semSimbolos = "";

	// Converte todas as letras maiúsculas para minúsculas
	for(unsigned int i = 0; i < s.length(); i++) {
		if(isupper(s[i]))
			s[i] = tolower(s[i]);
	}

	// Produz uma nova string sem símbolos
	for(unsigned int i = 0; i < s.length(); i++) {
		if(
			(s[i] >= 'a' && s[i] <= 'z') ||
			(s[i] >= '0' && s[i] <= '9')
		)
			semSimbolos += s[i];
	}

	int indiceReverso = semSimbolos.length() - 1, indice = 0;

	if(semSimbolos.length() < 2)
		return true;

	// Percorre a string pela frente e por trás
	while(indice < indiceReverso) {
		// Vê se o dígito da string crescente e da string decrescente são iguais
		if(semSimbolos[indice] != semSimbolos[indiceReverso])
			return false;

		indiceReverso--;
		indice++;
	}
	
	return true;
}

/* Given a reference (pointer to pointer)
to the head of a list and an int, inserts
a new node on the front of the list. */
void push(ListNode** head_ref, int new_data)
{
	/* 1. allocate node */
	ListNode* new_node = new ListNode();

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
	ListNode* head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 2);
	push(&head, 3);

	//printList(head);
	cout << isPalindrome(head);

	return 0;
}
