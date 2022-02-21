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

//노드 추가 
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

//데이터로 노드 찾기
void FindNode(Node* head, Node* tail, int find)
{
	Node* current = (Node*)malloc(sizeof(Node));

	current = head->next;
	while (current != NULL) {
		if (current->data == find)
		{
			printf("%d 값을 찾았습니다.\n", current->data);
		}
		current = current->next;
	}

}

//노드 출력 
void printNode(Node* head) {
	Node* current = (Node*)malloc(sizeof(Node));

	current = head->next;
	while (current != NULL) {
		printf("%d\n", current->data);
		//printf("%d..\n", current->data2);
		current = current->next;
	}
}

//데이터 찾아서 노드 삭제 
void DeleteNode(Node* head, Node* tail, int find)
{
	Node* previous = (Node*)malloc(sizeof(Node));
	Node* current = (Node*)malloc(sizeof(Node));

	current = head->next;
	while (current != NULL) {
		if (current->data == find)
		{
			printf("%d 값을 찾았습니다.\n", current->data);
			previous->next = current->next;
			free(current);
			break;
		}
		previous = current;
		current = current->next;
	}

}