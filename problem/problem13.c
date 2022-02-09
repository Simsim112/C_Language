#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGHTH 50

typedef struct bookInfo {
	char bookTitle[MAX_LENGHTH];
	char bookPub[MAX_LENGHTH];
	int bookPrice;
};
int MAX_BOOK = 3;
struct bookInfo bookInfo[50];
struct bookInfo* PtbookInfo = &bookInfo;

void PrintSortList();
int InsertList(struct bookInfo* bookPtr);
void SortByTitle();
void SortByPubName();
void SortByPrice();
void print_category();

int main() {

	struct bookInfo newbook;
	struct bookInfo* newPtbookInfo = &newbook;

	int choice;

	for (int i = 0; i < MAX_BOOK; i++)
	{
		scanf("%s", &PtbookInfo[i].bookTitle);
		scanf("%s", &PtbookInfo[i].bookPub);
		scanf("%d", &PtbookInfo[i].bookPrice);
	}

	while (1) {
		print_category();
		printf("선택:");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			PrintSortList();
			break;
		case 2:
			printf("추가할 새책 제목:");
			scanf("%s", &newPtbookInfo->bookTitle);
			printf("추가할 새책 타이틀 :");
			scanf("%s", &newPtbookInfo->bookPub);
			printf("추가할 새책 가격: ");
			scanf("%d", &newPtbookInfo->bookPrice);
			InsertList(newPtbookInfo);
		case 3:
			SortByTitle();
			break;
		case 4:
			SortByPubName();
			break;
		case 5:
			SortByPrice();
			break;
		case 6:
			exit(0);
		default:
			printf("1~6까지의 숫자를 선택해주세요\n");
			break;
		}
	}

	return 0;
}

//전체 출력 
void PrintSortList()
{
	for (int i = 0; i < MAX_BOOK; i++)
	{
		printf("%s ", PtbookInfo[i].bookTitle);
		printf("%s ", PtbookInfo[i].bookPub);
		printf("%d \n", PtbookInfo[i].bookPrice);
	}
}

//새거 넣고 도서이름 오름차순 배열 
int InsertList(struct bookInfo* bookPtr)
{
	int max, i;
	struct bookInfo temp;

	//새거 넣기
	for (i = MAX_BOOK; i < MAX_BOOK + 1; i++)
	{
		strcpy(PtbookInfo[i].bookTitle, bookPtr->bookTitle);
		strcpy(PtbookInfo[i].bookPub, bookPtr->bookPub);
		PtbookInfo[i].bookPrice = bookPtr->bookPrice;
	}
	MAX_BOOK++;

	//오름차순 정렬
	for (i = 0; i < MAX_BOOK; i++) {
		max = i;
		for (int j = i; j < MAX_BOOK; j++) {
			if (strcmp(PtbookInfo[max].bookTitle, PtbookInfo[j].bookTitle, 1) == 1)
				max = j;
		}
		temp = PtbookInfo[max];
		PtbookInfo[max] = PtbookInfo[i];
		PtbookInfo[i] = temp;
	}
}

//타이틀 오름차순 배열 
void SortByTitle() {
	int i, max;
	struct bookInfo temp;

	//오름차순 정렬
	for (i = 0; i < MAX_BOOK; i++) {
		max = i;
		for (int j = i; j < MAX_BOOK; j++) {
			if (strcmp(PtbookInfo[max].bookTitle, PtbookInfo[j].bookTitle, 1) == 1)
				max = j;
		}
		temp = PtbookInfo[max];
		PtbookInfo[max] = PtbookInfo[i];
		PtbookInfo[i] = temp;
	}
}

//출판사명 오름차순 배열 
void SortByPubName() {
	int i, max;
	struct bookInfo temp;

	//오름차순 정렬
	for (i = 0; i < MAX_BOOK; i++) {
		max = i;
		for (int j = i; j < MAX_BOOK; j++) {
			if (strcmp(PtbookInfo[max].bookPub, PtbookInfo[j].bookPub, 1) == 1)
				max = j;
		}
		temp = PtbookInfo[max];
		PtbookInfo[max] = PtbookInfo[i];
		PtbookInfo[i] = temp;
	}
}

//가격 오름차순 배열 
void SortByPrice() {
	int i, max;
	struct bookInfo temp;

	//오름차순 정렬
	for (i = 0; i < MAX_BOOK; i++) {
		max = i;
		for (int j = i; j < MAX_BOOK; j++) {
			if (PtbookInfo[max].bookPrice > PtbookInfo[j].bookPrice)
				max = j;
		}
		temp = PtbookInfo[max];
		PtbookInfo[max] = PtbookInfo[i];
		PtbookInfo[i] = temp;
	}
}

void print_category() {
	printf("------------------------------\n");
	printf("(1) 현재 등록된 책 전체보기\n");
	printf("(2) 새책 추가하기\n");
	printf("(3) 제목순으로 정렬하기\n");
	printf("(4) 출판사순으로 정렬하기\n");
	printf("(5) 가격순으로 정렬하기\n");
	printf("(6) 종료\n");
	printf("------------------------------\n");
}
