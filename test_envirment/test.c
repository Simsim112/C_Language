#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGHTH 50

typedef struct bookInfo{
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
		printf("����:");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			PrintSortList();
			break;
		case 2:
			printf("�߰��� ��å ����:");
			scanf("%s", &newPtbookInfo->bookTitle);
			printf("�߰��� ��å Ÿ��Ʋ :");
			scanf("%s", &newPtbookInfo->bookPub);
			printf("�߰��� ��å ����: ");
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
			printf("1~6������ ���ڸ� �������ּ���\n");
			break;
		}
	}

	return 0;
}

//��ü ��� 
void PrintSortList() 
{
	for (int i = 0; i < MAX_BOOK; i++)
	{
		printf("%s ", PtbookInfo[i].bookTitle);
		printf("%s ", PtbookInfo[i].bookPub);
		printf("%d \n", PtbookInfo[i].bookPrice);
	}
}

//���� �ְ� �����̸� �������� �迭 
int InsertList(struct bookInfo* bookPtr) 
{
	int max , i;
	struct bookInfo temp;

	//���� �ֱ�
	for (i = MAX_BOOK; i < MAX_BOOK + 1; i++)
	{
		strcpy(PtbookInfo[i].bookTitle, bookPtr->bookTitle);
		strcpy(PtbookInfo[i].bookPub, bookPtr->bookPub);
		PtbookInfo[i].bookPrice = bookPtr->bookPrice;
	}
	MAX_BOOK++;

	//�������� ����
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

//Ÿ��Ʋ �������� �迭 
void SortByTitle() {
	int i, max;
	struct bookInfo temp;

	//�������� ����
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

//���ǻ�� �������� �迭 
void SortByPubName() {
	int i, max;
	struct bookInfo temp;

	//�������� ����
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

//���� �������� �迭 
void SortByPrice() {
	int i, max;
	struct bookInfo temp;

	//�������� ����
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
	printf("(1) ���� ��ϵ� å ��ü����\n");
	printf("(2) ��å �߰��ϱ�\n");
	printf("(3) ��������� �����ϱ�\n");
	printf("(4) ���ǻ������ �����ϱ�\n");
	printf("(5) ���ݼ����� �����ϱ�\n");
	printf("(6) ����\n");
	printf("------------------------------\n");
}
