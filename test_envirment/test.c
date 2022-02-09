#include <Stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGHTH 50 

typedef struct bookInfo {
	char bookTitle[MAX_LENGHTH];
	char bookPub[MAX_LENGHTH];
	int bookPrice;
	struct bookInfo* next;
}BookInfo;

void FirstNode(BookInfo* head);
void printNode(BookInfo* head);

int main() {

	BookInfo* head = (BookInfo*)malloc(sizeof(BookInfo));
	BookInfo* my = (BookInfo*)malloc(sizeof(BookInfo));
	printf("%p\n", head);
	FirstNode(head);
	printf("%p\n", head);
	printNode(head);
	free(head);

	return 0;
}

//첫번째 노드 생성 
void FirstNode(BookInfo* head) {
	BookInfo* my = (BookInfo*)malloc(sizeof(BookInfo));
	printf("%p my my \n", my);
	head = my;
	printf("%p..\n", head);
}

void printNode( BookInfo* head) {
	printf("%p", head);
}