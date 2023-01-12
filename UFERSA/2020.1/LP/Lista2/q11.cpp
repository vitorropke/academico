#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
	ListNode *ponteiroLento = head, *ponteiroRapido = head;

	while(ponteiroLento && ponteiroRapido && ponteiroRapido->next) {
		ponteiroLento = ponteiroLento->next;
		ponteiroRapido = ponteiroRapido->next->next;

		if(ponteiroLento == ponteiroRapido) // Quando o ponteiro rapido alcançar o lento, isso significa que existe loop
			return true;
	}
	return false;
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

	newNode = new ListNode(1);
	newNode->val = 6;
	head1->next = newNode;

	newNode = new ListNode(1);
	newNode->val = 9;
	head1->next->next = newNode;

	newNode = new ListNode(1);
	newNode->val = 15;
	head1->next->next->next = newNode;

	newNode = new ListNode(1);
	newNode->val = 30;
	head1->next->next->next->next = newNode;

	head1->next->next->next->next->next = head1;

	//printList(head1);

	//cout << '\n';
	cout << hasCycle(head1);

	return 0;
}
