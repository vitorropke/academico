#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
	// Copy data of the next node to current node
	node->val = node->next->val;

	// Perform conventional deletion
	node->next = node->next->next;
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
	ListNode* head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);

	printList(head);

	deleteNode(head->next);
	cout << '\n';

	printList(head);

	return 0;
}
