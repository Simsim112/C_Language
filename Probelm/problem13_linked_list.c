#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

typedef struct bookInfo {
	char bookTitle[MAX_LENGTH];
	char bookPub[MAX_LENGTH];
	int bookPrice;
	struct bookInfo *next;
}BookInfo;

void FirstNode(BookInfo* head, BookInfo* current);
void AddNode(BookInfo* head, BookInfo* current);
void PrintNode(BookInfo* head, BookInfo* current);

int main() 
{
	BookInfo* head = (BookInfo*)malloc(sizeof(BookInfo));
	BookInfo* current = (BookInfo*)malloc(sizeof(BookInfo));

	FirstNode(head, current);
	AddNode(head, current);
	PrintNode(head, current);

	free(head);
	free(current);
}

void FirstNode(BookInfo * head, BookInfo* current)
{
	BookInfo* bookList = (BookInfo*)malloc(sizeof(BookInfo));
	head->next = bookList;
	current = head;
	strcpy(current->bookTitle, "¾î¸°¿ÕÀÚ");
	current->next = NULL;
}

void AddNode(BookInfo* head, BookInfo* current)
{
	BookInfo* bookList = (BookInfo*)malloc(sizeof(BookInfo));
	current->next = bookList;
	current = current->next;
	strcpy(current->bookTitle, "¾î¸°¿ÕÀÚ2");
	
	current->next = NULL;
}
void PrintNode(BookInfo* head, BookInfo* current)
{
	current = head;
	while (current != NULL) {
		printf("%s", current->bookTitle);
		current = current->next;
	}
}