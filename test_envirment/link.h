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

//노드 추가 
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

//데이터로 노드 찾기
void FindNode(Node* head, Node* tail, int find)
{
	Node* current = (Node*)malloc(sizeof(Node));

	current = head;
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
		current = current->next;
	}
}

