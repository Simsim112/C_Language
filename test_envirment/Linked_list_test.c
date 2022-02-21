#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	int data2;
	struct node* next;
}Node;

void AddNode(Node* head, Node* tail, int data, int data2);
void FindNode(Node* head, Node* tail, int find);
void DeleteNode(Node* head, Node* tail, int find);
void printNode(Node* head);

int main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	Node* tail = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	int j = 11;
	for (int i = 0; i < 10; i++) {
		AddNode(head, tail, i, j);
		j++;
	}
	printNode(head);
	DeleteNode(head, tail, 8);
	printNode(head);
	return 0;
}

//��� �߰� 
void AddNode(Node* head, Node* tail, int data, int data2)
{
	Node* node = (Node*)malloc(sizeof(Node));
	Node* current = (Node*)malloc(sizeof(Node));
	node->data = data;

	node->next = NULL;

	if (head->next == NULL) {
		head->next = node;

	}
	else {
		tail->next->next = node;

	}

	tail->next = node;

}

//�����ͷ� ��� ã��
void FindNode(Node* head, Node* tail, int find)
{
	Node* current = (Node*)malloc(sizeof(Node));

	current = head->next;
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
		//printf("%d..\n", current->data2);
		current = current->next;
	}
}

//������ ã�Ƽ� ��� ���� 
void DeleteNode(Node* head, Node* tail, int find)
{
	Node* previous = (Node*)malloc(sizeof(Node));
	Node* current = (Node*)malloc(sizeof(Node));

	current = head->next;
	while (current != NULL) {
		if (current->data == find)
		{
			printf("%d ���� ã�ҽ��ϴ�.\n", current->data);
			previous->next = current->next;
			free(current);
			break;
		}
		previous = current;
		current = current->next;
	}

}