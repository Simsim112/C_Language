#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

void AddNode(Node* head, Node* tail, int data);
void FindNode(Node* head, Node* tail, int find);
void DeleteNode(Node* head, Node* tail, int find);
void printNode(Node* head);

int main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	Node* tail = (Node*)malloc(sizeof(Node));
	head = NULL;

	AddNode(head, tail, 10);

	//printNode(head);
	//DeleteNode(head, tail, 8);
	//printNode(head);
	return 0;
}

//��� �߰� 
void AddNode(Node* head, Node* tail, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	Node* current = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (head == NULL) {
		head = node;
		tail = node;

	}
	else {
		tail->next = node;
		tail = node;

	}
}

//�����ͷ� ��� ã��
void FindNode(Node* head, Node* tail, int find)
{
	Node* current = (Node*)malloc(sizeof(Node));

	current = head;
	while (current != NULL) {
		if (current->data == find)
		{
			printf("%d ���� ã�ҽ��ϴ�.\n", current->data);
		}
		current = current->next;
	}

}

//��� ��� 
void printNode(Node* head) {
	Node* current = (Node*)malloc(sizeof(Node));

	current = head->next;
	while (current != NULL) {
		printf("%d\n", current->data);
		current = current->next;
	}
}

