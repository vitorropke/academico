#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* listaJunta = NULL;
	ListNode* novoNo;
	vector<int> vetorJunto;

	while(l1 != NULL) { // Lista 1 para vetor
		vetorJunto.push_back(l1->val);

		l1 = l1->next;
	}

	while(l2 != NULL) { // Lista 2 para vetor
		vetorJunto.push_back(l2->val);

		l2 = l2->next;
	}

	sort(vetorJunto.begin(), vetorJunto.end()); // Ordena vetor

	for(int i = vetorJunto.size() - 1; i > -1; i--) { // Coloca o vetor na lista
		novoNo = new ListNode;
		novoNo->val = vetorJunto[i];
		novoNo->next = listaJunta;
		listaJunta = novoNo;
	}

	return listaJunta;
}

/* Given a reference (pointer to pointer)
to the head of a list and an int, inserts
a new node on the front of the list. */
void push(ListNode** head_ref, int new_data)
{
	/* 1. allocate node */
	ListNode* new_node = new ListNode;

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
	ListNode* head1 = new ListNode;
	head1->val = 10;

	newNode = new ListNode;
	newNode->val = 6;
	head1->next = newNode;

	newNode = new ListNode;
	newNode->val = 9;
	head1->next->next = newNode;

	newNode = new ListNode;
	newNode->val = 15;
	head1->next->next->next = newNode;

	newNode = new ListNode;
	newNode->val = 30;
	head1->next->next->next->next = newNode;

	head1->next->next->next->next->next = NULL;

	// Adiciona a segunda lista
	ListNode* head2 = new ListNode;
	head2->val = 2;

	newNode = new ListNode;
	newNode->val = 6;
	head2->next = newNode;

	newNode = new ListNode;
	newNode->val = 1;
	head2->next->next = newNode;

	newNode = new ListNode;
	newNode->val = 7;
	head2->next->next->next = NULL;

	//printList(head1);

	cout << '\n';

	//printList(head2);

	printList(mergeTwoLists(head1, head2));

	return 0;
}
