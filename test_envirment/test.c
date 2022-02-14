#include <stdio.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

void Addnode(Node* head, Node* tail, int data);
void Add(Node* head, Node* tail, int data);
void printNode(Node* head);

int main() 
{
	Node* head = malloc(sizeof(Node));
	Node* tail = malloc(sizeof(Node));

	Addnode(head, tail, 10);

	printf("%p\n", head->next);
	printf("%p\n", tail->next);
	Add(head, tail, 20);
	//Add(head, tail, 30);
	//printNode(head, tail);
	return 0;
}

void Addnode(Node* head, Node* tail, int data)
{
	Node* node = malloc(sizeof(Node));

	node->data = data;
	node->next = NULL;

	head = node;
	tail = node;
	printf("%p\n", node->next);
	printf("%p\n", head->next);
	printf("%p\n", tail->next);
}

void Add(Node* head, Node* tail, int data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	tail->next = node;
	tail = node;

}

void printNode(Node* head) {
	Node* current = malloc(sizeof(Node));
	int i=0;

	if (head->next != NULL) {
		printf("%d...\n", head->data);
		head = head->next;
	}
}