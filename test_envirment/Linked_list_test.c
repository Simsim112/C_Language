#include <stdio.h>

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
	Node* head = malloc(sizeof(Node));
	Node* tail = malloc(sizeof(Node));
	head->next = NULL;

	for (int i = 0; i < 10; i++) {
		AddNode(head, tail, i);
	}
	printNode(head);
	DeleteNode(head, tail, 8);
	printNode(head);
	return 0;
}

//��� �߰� 
void AddNode(Node* head, Node* tail, int data)
{
	Node* node = malloc(sizeof(Node));
	Node* current = malloc(sizeof(Node));
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
	Node* current = malloc(sizeof(Node));

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
	Node* current = malloc(sizeof(Node));

	current = head->next;
	while (current != NULL) {
		printf("%d\n", current->data);
		current = current->next;
	}
}

//������ ã�Ƽ� ��� ���� 
void DeleteNode(Node* head, Node* tail, int find)
{
	Node* previous = malloc(sizeof(Node));
	Node* current = malloc(sizeof(Node));

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