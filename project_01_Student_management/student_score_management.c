#include <stdio.h>
#include <string.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS

void selleradd(struct basic bas[], int count, int i);
void sellerlook(struct basic bas[], int count, int i);
void sellerupdate(struct basic bas[], int count, int i);
void sellersh(struct basic bas[], int count, int i);
void del(struct basic bas[], int count, int i);

/*�޴������Լ�*/
int Menu1();
void moveMenu();

struct basic
{
    char name[20], add[20];
    int num, nums;

}bas[100]; //����ü����


/*�����Լ�*/
void main()
{
    int i = 0;
    int count = 0; // ����ī����  

    while (1)
    {


        int Menu = Menu1(); //�޴����� �Լ�

        switch (Menu) {
        case 1: //���Ե��
            selleradd(bas, count, i);
            count++;
            break;

        case 2:
            sellerlook(bas, count, i);
            break;

        case 3:
            sellerupdate(bas, count, i);
            break;

        case 4:
            sellersh(bas, count, i);
            break;

        case 5:
            del(bas, count, i);
            break;
        }

    }
}
int Menu1()
{
    int mainmenu;

    printf("                                        \n");
    printf(" **      ****         �ڹ���� ������   \n");
    printf(" **    *                                \n");
    printf(" *** **                                 \n");
    printf(" *******            *************       \n");
    printf(" *******            **************      \n");
    printf(" *******            **************      \n");
    printf(" *******************  ******  ****      \n");
    printf(" ******************* ******** ****      \n");
    printf("  ******              ******            \n");
    printf("   ****                ****             \n");
    printf("                                        \n");


    printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
    printf("---------------------------\n");
    printf("(1)���Ե��(2)������ü����\n(3)���Լ���\n(4)���԰˻�\n(5)���Ի���\n");
    printf("�̵��Ͻ� ��ȣ�� �Է����ּ���\n");
    printf("---------------------------\n");


    scanf("%d", &mainmenu);


    return mainmenu;
}


void moveMenu()
{
    printf("\n����Ͻ÷��� ����Ű�� ��������.\n");
    getch();
}

void selleradd(struct basic bas[], int count)
{
    char names[100];
    char adds[100];


    printf("���Ը� ������ּ���!\n");
    scanf("%s", names);
    strcpy(bas[count].name, names);

    printf("�ּҸ� ������ּ���!\n");
    scanf("%s", adds);
    strcpy(bas[count].add, adds);

    printf("��ȭ��ȣ�� �Է����ּ���!\n");
    scanf("%d%d", &bas[count].num, &bas[count].nums);

    printf("%s : %s :%d-%d,%d", bas[count].name, bas[count].add, bas[count].num, bas[count].nums, count);
    moveMenu();

}
void sellerlook(struct basic bas[], int count, int i)
{

    printf("********������ü��ȸâ�Դϴ�*****\n");
    for (i = 0; i < count; i++)
    {
        printf("%5s%10s%20d-%d\n", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);

    }
    printf("�����մϴ�.");


}
void sellerupdate(struct basic bas[], int count, int i)
{
    char names[100];

    printf("������ ���Ը� �Է����ּ���\n:");
    scanf("%s", names);

    for (i = 0; i < count; i++)
    {
        if ((!strcmp(names, &bas[i].name)))
        {
            printf("�����Ͻ� ��ȣ��(�������)�� �Է����ּ���:\n");
            scanf("%s", &bas[i].name);
            printf("�ּҸ��Է����ּ���\n");
            scanf("%s", &bas[i].add);
            printf("��ȭ��ȣ���Է����ּ���.\n");
            scanf("%d%d", &bas[i].num, &bas[i].nums);

            printf("%s %s %d-%d�� �����Ǿ����ϴ�(%d).", bas[i].name, bas[i].add, bas[i].num, bas[i].nums, count);


        }
    }

}
void sellersh(struct basic bas[], int count, int i)
{
    char names[100];

    printf("�˻��� ���Ը� �Է����ּ���\n:");
    scanf("%s", names);

    for (i = 0; i < count; i++)
    {
        if ((!strcmp(names, bas[i].name)))
        {
            printf("%s %10s %20d-%d", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
            printf("�����մϴ�.");
        }
        else
        {
            printf("ã���ô� ���԰� �����ϴ�.");
        }
    }
}

void del(struct basic bas[], int count, int i)
{
    int j;
    char names[20];

    printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
    printf("---------------------------\n");
    printf("������ ���Ը� �Է����ּ���\n:");
    scanf("%s", names);

    for (i = 0; i < count; i++)
    {
        if ((!strcmp(names, &bas[i].name)))
        {
            for (j = i; i < count; j++)
            {
                bas[j] = bas[j + 1];
            }

        }

        else
            printf("ã���ô� ���԰� �����ϴ�.");
    }
    count--;
}