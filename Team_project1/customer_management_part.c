#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Number_of_Customer 30
//�� : �̸�, ��ȭ��ȣ, �ּ�

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

//���κκ� 
int main() { //�� CURD ����, ������Ʈ, ���, ����
	int choice  = 0, choice2 = 0;
	struct count count = { 0,0,2 };
	customer customer[Number_of_Customer];
	testdata(customer);

	while (1) {
		printf("���� ������\n");
		choice = Customer_Select(choice);
		switch (choice)
		{
		case 1:
			printf("���� �Ǹ��� ���� ����\n");
			break;
			while (1)
			{
			case 2:
				Customer_print_category1();
				choice2 = Customer_Select(choice2);
				switch (choice2)
				{
				//�� CURD ����
				case 1:
					Customer_add(customer, count);
					count.customer++;
					break;

				//������Ʈ
				case 2:
					Customer_update(customer, count);
					break;

				//���
				case 3:
					Customer_look(customer, count);
					break;

				//����
				case 4:
					Customer_delete(customer, count);
					break;

				//���� 
				case 5:
					Customer_recovery(customer, count);
					break;

				//���� 
				case 6:
					break;

				//����Ʈ �� 
				default:
					printf("1~6������ ���ڸ� �Է����ּ���\n");
				}
			if (choice2 == 6)
				break;
			}
		default:
			printf("1~2������ ���ڸ� �Է����ּ���\n");
			break;
		}

	}
	return 0;
}

//�� �Է�
void Customer_add(customer customer[], struct count count)
{
	char name[10], address[100];
	int call;
	customer[count.customer].del = 0;
	system("cls");
	printf("	<�����������>	\n\n");
	printf("����� �̸��� �Է����ּ���: ");
	gets(customer[count.customer].name);
	printf("����� ��ȭ��ȣ�� �Է����ּ���: ");
	gets(customer[count.customer].phone);
	printf("����� �ּҸ� �Է����ּ���: ");
	gets(customer[count.customer].address);
	printf("����� ������ �ԷµǾ����ϴ�.\n");
}

//�� ������Ʈ
void Customer_update(customer customer[], struct count count)
{
	int choice = 0, number = 0;
	char name[10], name1[10], call[20], address[100];
	while (1)
	{
		if (count.customer == 0) //��ϵ� ���� �Ѹ� ���� ��
		{
			printf("��ϵ� ���� �Ѹ� �����ϴ�.\n");
			break;
		}
		else 
		{ //��ϵ� ���� ���� ��� 
			printf("�����Ϸ��� ����ȣ�� �Է����ּ���: ");
			scanf("%d%*c", &number);
			for (int i = 0; i < count.customer; i++)
			{
				if (i == number) //ã�� ���� ���� ���
				{
					if (customer[i].del == 1)
					{
						printf("�̹� ������ ���Դϴ�.\n");
						break;
					}
					else
					{
						printf("��ȣ	�̸�		��ȭ��ȣ		�ּ�\n");
						printf("----------------------------------------------------------------\n");
						printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
						Customer_print_category2();
						while (1)
						{
							choice = Customer_Select(choice);
							switch (choice)
							{
							case 1:
								printf("������ �̸��� �Է����ּ���: ");
								scanf("%s", name1);
								strcpy(customer[i].name, name1);
								printf("�̸��� %s���� �����Ǿ����ϴ�.\n\n", customer[i].name);
								break;
							case 2:
								printf("������ ��ȭ��ȣ�� �Է����ּ���: ");
								scanf("%s", call);
								strcpy(customer[i].phone, call);
								printf("��ȭ��ȣ�� %s���� �����Ǿ����ϴ�.\n\n", customer[i].phone);
								break;
							case 3:
								printf("������ �ּҸ� �Է����ּ���: ");
								gets(address);
								strcpy(customer[i].address, address);
								printf("�ּҰ� %s���� �����Ǿ����ϴ�.\n\n", customer[i].address);
								break;
							default:
								printf("1~3������ ���ڸ� �Է����ּ���\n");
								break;
							}
							break;
						}
					}
					break;
				}
				else if (i == count.customer - 1 ) //�� ã�ƺ��� ������� 
				{
					printf("�ش��ϴ� ���� �����ϴ�. \n");
					break;
				}
			}
		}
		break;
	}
}

//�� ���
void Customer_look(customer customer[], struct count count)
{
	int choice = 0, count1 = 0, count2 = 0;
	char name[20];
	system("cls");
	while (1)
	{
		if (count.customer == 0) //��ϵ� ���� �Ѹ� ���� ��
		{
			printf("��ϵ� ���� �Ѹ� �����ϴ�.\n");
			break;
		}
		else
		{ //��ϵ� ���� ���� ��� 
			printf("��� ���� ����Ͻ÷��� 1�� �Է��Ͻðų�\n");
			printf("ã���÷��� ������ �Է����ּ���: ");
			scanf("%s%*c", name);
			if (!strcmp("1",name))
			{
				Customer_all_look(customer, count);
				break;
			}
			for (int i = 0; i < count.customer; i++)
			{
				if(!strcmp(customer[i].name, name)) //ã�� ���� ���� ���
				{
					if (customer[i].del == 1)
					{
						printf("�̹� ������ ���Դϴ�.\n");
						count1 = 1;
						//break;
					}
					else
					{
						if (count2 == 0) 
						{
						printf("%s�� �ش��ϴ� ���� ã�ҽ��ϴ�.\n", name);
						printf("��ȣ	�̸�		��ȭ��ȣ		�ּ�\n");
						printf("----------------------------------------------------------------\n");
						printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
						count2 = 1;
						}
						printf("%3d	 %s	%s	%13s\n", i, customer[i].name, customer[i].phone, customer[i].address);
						count1 = 1;
						//break;
					}
				}
				else if (i == count.customer - 1 && count1 == 0) //�� ã�ƺ��� ������� 
				{
					printf("%s�� �ش��ϴ� ���� �����ϴ�. \n", name);
					//break;
				}
			}
		}
		break;
	}
}

//�� ����
void Customer_delete(customer customer[], struct count count)
{
	int choice = 0,number = 0;
	char name[10];
	char name2[10];
	while (1)
	{
		if (count.customer == 0) //��ϵ� ���� �Ѹ� ���� ��
		{
			printf("��ϵ� ���� �Ѹ� �����ϴ�.\n");
			break;
		}
		else
		{ //��ϵ� ���� ���� ��� 
			printf("������ ��� ���� ����Ͻ÷��� s�� �Է��Ͻðų�\n");
			printf("�����Ͻ÷��� ����ȣ�� �Է����ּ���: ");
			scanf("%s%*c", name);
			if (!strcmp("s",name))
			{
				Customer_delete_all_look(customer, count);
				break;
			}
			for (int i = 0; i < count.customer; i++)
			{
				if(i == atoi(name) && Customer_check(name) == 0) //ã�� ���� ���� ���
				{
					if (customer[i].del == 1)
					{
						printf("�̹� ������ ���Դϴ�.\n");
						break;
					}
					else
					{
						printf("%s�� �ش��ϴ� ���� ã�ҽ��ϴ�.\n", customer[i].name);
						printf("��ȣ	�̸�		��ȭ��ȣ		�ּ�\n");
						printf("----------------------------------------------------------------\n");
						printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
						printf("������ �����Ͻðڽ��ϱ�?\n");
						printf("�����Ͻ÷��� ���̸��� �Է����ּ���: ");
						scanf("%s", name2);
						if (!strcmp(customer[i].name, name2)) //�Է��ؼ� ���� ��� 
						{
							customer[i].del = 1;
							printf("%s ���� �����Ǿ����ϴ�.\n", customer[i].name);
							break;
						}
						else
						{
							printf("�����Ϸ��� ������ Ʋ���ϴ�.\n");
							break;
						}
					}
					break;
				}
				else if (i == count.customer - 1) //�� ã�ƺ��� ������� 
				{
					printf("�ش��ϴ� ���� �����ϴ�. \n");
					break;
				}
			}
		}
		break;
	}
}

//�� ����
void Customer_recovery(customer customer[], struct count count)
{
	int choice = 0, number = 0;
	char name[10];
	char name2[10];
	while (1)
	{
		if (count.customer == 0) //��ϵ� ���� �Ѹ� ���� ��
		{
			printf("��ϵ� ���� �Ѹ� �����ϴ�.\n");
			break;
		}
		else
		{ //��ϵ� ���� ���� ��� 
			printf("�����Ϸ��� ����ȣ�� �Է����ּ���: ");
			scanf("%d", &number);
			for (int i = 0; i < count.customer; i++)
			{
				if (i == number)
				{
					if (customer[i].del == 0)
					{
						printf("������ ȸ���� �ƴմϴ�.\n");
					}
					else 
					{
						printf("������ �� %s�� ã�ҽ��ϴ�.\n", customer[i].name);
						printf("��ȣ	�̸�		��ȭ��ȣ		�ּ�\n");
						printf("----------------------------------------------------------------\n");
						printf("%3d %10s %18s %18s\n", i, customer[i].name, customer[i].phone, customer[i].address);
						printf("�����Ͻ÷��� �̸��� �ٽ� �Է����ּ���: ");
						scanf("%s%*c", name2);
						if (!strcmp(customer[i].name, name2)) //�ٽ��Է��ؼ� ���� ��� 
						{
							customer[i].del = 0;
							printf("%s ���� �����Ǿ����ϴ�.\n", customer[i].name);
							break;
						}
						else
						{
							printf("�����Ϸ��� ������ Ʋ���ϴ�.\n");
							break;
						}
					}
				}
				else if (i == count.customer - 1) //�� ã�ƺ��� ������� 
				{
					printf("�����Ϸ��� ���� ã������ �����ϴ�. \n");
					break;
				}
			}
		}
		break;
	}
}

//�� ���� ī�װ� 
void Customer_print_category1() {
	printf("(1) ����� \n");
	printf("(2) ������ ���� \n");
	printf("(3) ������ ��� \n");
	printf("(4) �� ���� \n");
	printf("(5) �� ���� \n");
	printf("(6) ���� �׸����� \n");
}

//�� update ī�װ� 
void Customer_print_category2() {
	printf("(1) �̸� ���� \n");
	printf("(2) ��ȭ��ȣ ���� \n");
	printf("(3) �ּҺ��� \n");
}

//����ġ�� ���� 
int Customer_Select(int choice)
{
	printf("�׸��� �������ּ���: ");
	scanf("%d%*c", &choice);
	return choice;
}

//�� ��ü ��� 
void Customer_all_look(customer customer[], struct count count)
{
	printf("��ȣ	�̸�		��ȭ��ȣ		�ּ�\n");
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

//������ �� ��ü ��� 
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
		printf("��ȣ	�̸�		��ȭ��ȣ		�ּ�\n");
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
		printf("������ ���� �Ѹ� �����ϴ�.\n");
}

//�׽�Ʈ ������
void testdata(customer customer[])
{
	strcpy(customer[0].name, "����");
	strcpy(customer[0].phone, "010-2352-7813");
	strcpy(customer[0].address, "��õ��");
	customer[0].del = 0;

	strcpy(customer[1].name, "���ñ��");
	strcpy(customer[1].phone, "010-3209-1557");
	strcpy(customer[1].address, "�뿬��");
	customer[1].del = 0;
}

//�������� üũ
int Customer_check(char name[])
{	
	for (int i = 0; i < 10; i++) {
		if ('0' <= name[i] && name[i] <= '9')
			return 0;
	}
	return 1;
}