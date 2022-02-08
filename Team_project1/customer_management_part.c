#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Number_of_Customer 30
//고객 : 이름, 전화번호, 주소

typedef struct{
	int del;
	char name[10];
	char phone[20];
	char address[100];
}customer;

struct count {
	int shop;
	int menu;
	int customer;
}count;

struct count count = { 0, };

void Customer_add(customer customer[], struct count count);
void Customer_look(customer customer[], struct count count);
void Customer_update(customer customer[], struct count count);
void Customer_delete(customer customer[], struct count count);
void Customer_recovery(customer customer[], struct count count);
void testdata(customer customer[]);
void Customer_all_look(customer customer[], struct count count);
void Customer_delete_all_look(customer customer[], struct count count);
int Customer_check(char name[]);
void Customer_print_category1();
void Customer_print_category2();
int Customer_Select(int choice);

//메인부분 
int main() { //고객 CURD 생성, 업데이트, 출력, 삭제
	int choice  = 0, choice2 = 0;
	struct count count = { 0,0,2 };
	customer customer[Number_of_Customer];
	testdata(customer);

	while (1) {
		printf("메인 페이지\n");
		choice = Customer_Select(choice);
		switch (choice)
		{
		case 1:
			printf("여기 판매자 정보 선택\n");
			break;
			while (1)
			{
			case 2:
				Customer_print_category1();
				choice2 = Customer_Select(choice2);
				switch (choice2)
				{
				//고객 CURD 생성
				case 1:
					Customer_add(customer, count);
					count.customer++;
					break;

				//업데이트
				case 2:
					Customer_update(customer, count);
					break;

				//출력
				case 3:
					Customer_look(customer, count);
					break;

				//삭제
				case 4:
					Customer_delete(customer, count);
					break;

				//복구 
				case 5:
					Customer_recovery(customer, count);
					break;

				//종료 
				case 6:
					break;

				//디폴트 값 
				default:
					printf("1~6사이의 숫자를 입력해주세요\n");
				}
			if (choice2 == 6)
				break;
			}
		default:
			printf("1~2사이의 숫자를 입력해주세요\n");
			break;
		}

	}
	return 0;
}

//고객 입력
void Customer_add(customer customer[], struct count count)
{
	char name[10], address[100];
	int call;
	customer[count.customer].del = 0;
	system("cls");
	printf("	<고객등록페이지>	\n\n");
	printf("사용자 이름을 입력해주세요: ");
	gets(customer[count.customer].name);
	printf("사용자 전화번호를 입력해주세요: ");
	gets(customer[count.customer].phone);
	printf("사용자 주소를 입력해주세요: ");
	gets(customer[count.customer].address);
	printf("사용자 정보가 입력되었습니다.\n");
}

//고객 업데이트
void Customer_update(customer customer[], struct count count)
{
	int choice = 0, number = 0;
	char name[10], name1[10], call[20], address[100];
	while (1)
	{
		if (count.customer == 0) //등록된 고객이 한명도 없을 때
		{
			printf("등록된 고객이 한명도 없습니다.\n");
			break;
		}
		else 
		{ //등록된 고객이 있을 경우 
			printf("수정하려는 고객번호를 입력해주세요: ");
			scanf("%d%*c", &number);
			for (int i = 0; i < count.customer; i++)
			{
				if (i == number) //찾는 고객이 있을 경우
				{
					if (customer[i].del == 1)
					{
						printf("이미 지워진 고객입니다.\n");
						break;
					}
					else
					{
						printf("번호	이름		전화번호		주소\n");
						printf("----------------------------------------------------------------\n");
						printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
						Customer_print_category2();
						while (1)
						{
							choice = Customer_Select(choice);
							switch (choice)
							{
							case 1:
								printf("수정할 이름을 입력해주세요: ");
								scanf("%s", name1);
								strcpy(customer[i].name, name1);
								printf("이름이 %s으로 수정되었습니다.\n\n", customer[i].name);
								break;
							case 2:
								printf("수정할 전화번호를 입력해주세요: ");
								scanf("%s", call);
								strcpy(customer[i].phone, call);
								printf("전화번호가 %s으로 수정되었습니다.\n\n", customer[i].phone);
								break;
							case 3:
								printf("수정할 주소를 입력해주세요: ");
								gets(address);
								strcpy(customer[i].address, address);
								printf("주소가 %s으로 수정되었습니다.\n\n", customer[i].address);
								break;
							default:
								printf("1~3사이의 숫자를 입력해주세요\n");
								break;
							}
							break;
						}
					}
					break;
				}
				else if (i == count.customer - 1 ) //다 찾아봐도 없을경우 
				{
					printf("해당하는 고객이 없습니다. \n");
					break;
				}
			}
		}
		break;
	}
}

//고객 출력
void Customer_look(customer customer[], struct count count)
{
	int choice = 0, count1 = 0, count2 = 0;
	char name[20];
	system("cls");
	while (1)
	{
		if (count.customer == 0) //등록된 고객이 한명도 없을 때
		{
			printf("등록된 고객이 한명도 없습니다.\n");
			break;
		}
		else
		{ //등록된 고객이 있을 경우 
			printf("모든 고객을 출력하시려면 1을 입력하시거나\n");
			printf("찾으시려는 고객명을 입력해주세요: ");
			scanf("%s%*c", name);
			if (!strcmp("1",name))
			{
				Customer_all_look(customer, count);
				break;
			}
			for (int i = 0; i < count.customer; i++)
			{
				if(!strcmp(customer[i].name, name)) //찾는 고객이 있을 경우
				{
					if (customer[i].del == 1)
					{
						printf("이미 지워진 고객입니다.\n");
						count1 = 1;
						//break;
					}
					else
					{
						if (count2 == 0) 
						{
						printf("%s에 해당하는 고객을 찾았습니다.\n", name);
						printf("번호	이름		전화번호		주소\n");
						printf("----------------------------------------------------------------\n");
						printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
						count2 = 1;
						}
						printf("%3d	 %s	%s	%13s\n", i, customer[i].name, customer[i].phone, customer[i].address);
						count1 = 1;
						//break;
					}
				}
				else if (i == count.customer - 1 && count1 == 0) //다 찾아봐도 없을경우 
				{
					printf("%s에 해당하는 고객이 없습니다. \n", name);
					//break;
				}
			}
		}
		break;
	}
}

//고객 삭제
void Customer_delete(customer customer[], struct count count)
{
	int choice = 0,number = 0;
	char name[10];
	char name2[10];
	while (1)
	{
		if (count.customer == 0) //등록된 고객이 한명도 없을 때
		{
			printf("등록된 고객이 한명도 없습니다.\n");
			break;
		}
		else
		{ //등록된 고객이 있을 경우 
			printf("삭제된 모든 고객을 출력하시려면 s를 입력하시거나\n");
			printf("삭제하시려는 고객번호를 입력해주세요: ");
			scanf("%s%*c", name);
			if (!strcmp("s",name))
			{
				Customer_delete_all_look(customer, count);
				break;
			}
			for (int i = 0; i < count.customer; i++)
			{
				if(i == atoi(name) && Customer_check(name) == 0) //찾는 고객이 있을 경우
				{
					if (customer[i].del == 1)
					{
						printf("이미 지워진 고객입니다.\n");
						break;
					}
					else
					{
						printf("%s에 해당하는 고객을 찾았습니다.\n", customer[i].name);
						printf("번호	이름		전화번호		주소\n");
						printf("----------------------------------------------------------------\n");
						printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
						printf("정말로 삭제하시겠습니까?\n");
						printf("삭제하시려면 고객이름을 입력해주세요: ");
						scanf("%s", name2);
						if (!strcmp(customer[i].name, name2)) //입력해서 같을 경우 
						{
							customer[i].del = 1;
							printf("%s 고객이 삭제되었습니다.\n", customer[i].name);
							break;
						}
						else
						{
							printf("삭제하려는 고객명이 틀립니다.\n");
							break;
						}
					}
					break;
				}
				else if (i == count.customer - 1) //다 찾아봐도 없을경우 
				{
					printf("해당하는 고객이 없습니다. \n");
					break;
				}
			}
		}
		break;
	}
}

//고객 복구
void Customer_recovery(customer customer[], struct count count)
{
	int choice = 0, number = 0;
	char name[10];
	char name2[10];
	while (1)
	{
		if (count.customer == 0) //등록된 고객이 한명도 없을 때
		{
			printf("등록된 고객이 한명도 없습니다.\n");
			break;
		}
		else
		{ //등록된 고객이 있을 경우 
			printf("복구하려는 고객번호를 입력해주세요: ");
			scanf("%d", &number);
			for (int i = 0; i < count.customer; i++)
			{
				if (i == number)
				{
					if (customer[i].del == 0)
					{
						printf("삭제된 회원이 아닙니다.\n");
					}
					else 
					{
						printf("삭제된 고객 %s를 찾았습니다.\n", customer[i].name);
						printf("번호	이름		전화번호		주소\n");
						printf("----------------------------------------------------------------\n");
						printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
						printf("복구하시려면 이름을 다시 입력해주세요: ");
						scanf("%s%*c", name2);
						if (!strcmp(customer[i].name, name2)) //다시입력해서 같을 경우 
						{
							customer[i].del = 0;
							printf("%s 고객이 복구되었습니다.\n", customer[i].name);
							break;
						}
						else
						{
							printf("복구하려는 고객명이 틀립니다.\n");
							break;
						}
					}
				}
				else if (i == count.customer - 1) //다 찾아봐도 없을경우 
				{
					printf("복구하려는 고객을 찾을수가 없습니다. \n");
					break;
				}
			}
		}
		break;
	}
}

//고객 설정 카테고리 
void Customer_print_category1() {
	printf("(1) 고객등록 \n");
	printf("(2) 고객정보 수정 \n");
	printf("(3) 고객정보 출력 \n");
	printf("(4) 고객 삭제 \n");
	printf("(5) 고객 복구 \n");
	printf("(6) 상위 항목으로 \n");
}

//고객 update 카테고리 
void Customer_print_category2() {
	printf("(1) 이름 수정 \n");
	printf("(2) 전화번호 수정 \n");
	printf("(3) 주소변경 \n");
}

//스위치문 선택 
int Customer_Select(int choice)
{
	printf("항목을 선택해주세요: ");
	scanf("%d%*c", &choice);
	return choice;
}

//고객 전체 출력 
void Customer_all_look(customer customer[], struct count count)
{
	printf("번호	이름		전화번호		주소\n");
	printf("----------------------------------------------------------------\n");
	for (int i = 0; i < count.customer; i++)
	{
		if (customer[i].del == 1)
			continue;
		else 
		{
			printf("%3d %10s %18s %18s", i, customer[i].name, customer[i].phone, customer[i].address);
			printf("\n");
		}
	}
}

//삭제된 고객 전체 출력 
void Customer_delete_all_look(customer customer[], struct count count)
{
	int count1 = 0;

	for (int i = 0; i < count.customer; i++)
	{
		if (customer[i].del == 1)
			count1 = 1;
	}

	if (count1 == 1) 
	{
		printf("번호	이름		전화번호		주소\n");
		printf("----------------------------------------------------------------\n");
		for (int i = 0; i < count.customer; i++)
		{
			if (customer[i].del == 0)
				continue;
			else
			{
				printf("%3d	 %s	%s	%13s", i, customer[i].name, customer[i].phone, customer[i].address);
				printf("\n");
			}
		}
	}
	else
		printf("삭제된 고객이 한명도 없습니다.\n");
}

//테스트 데이터
void testdata(customer customer[])
{
	strcpy(customer[0].name, "김김김");
	strcpy(customer[0].phone, "010-2352-7813");
	strcpy(customer[0].address, "남천동");
	customer[0].del = 0;

	strcpy(customer[1].name, "남궁김김");
	strcpy(customer[1].phone, "010-3209-1557");
	strcpy(customer[1].address, "대연동");
	customer[1].del = 0;
}

//숫자인지 체크
int Customer_check(char name[])
{	
	for (int i = 0; i < 10; i++) {
		if ('0' <= name[i] && name[i] <= '9')
			return 0;
	}
	return 1;
}