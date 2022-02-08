#include <stdio.h>
#include <string.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS

void selleradd(struct basic bas[], int count);
void sellerlook(struct basic bas[], int count);
void sellerupdate(struct basic bas[], int count);
void sellersh(struct basic bas[], int count);
void sellerdel(struct basic bas[], int count);
void sellerrecovery(struct basic bas[], int count);
void sampledata(struct basic bas[]);

/*�޴������Լ�*/
int Menu1();
void moveMenu();

struct basic
{
    char name[20], add[20];
    int del, num, nums;

}bas[100] = { 0, }; //����ü����


/*�����Լ�*/
void main()
{
    sampledata(bas);
    int i = 0;
    int count = 4; // ����ī����  

    while (1)
    {


        int Menu = Menu1(); //�޴����� �Լ�

        switch (Menu) {
        case 1: //���Ե��
            selleradd(bas, count);
            count++;
            break;

        case 2:
            sellerlook(bas, count);
            break;

        case 3:
            sellerupdate(bas, count);
            break;

        case 4:
            sellersh(bas, count);
            break;

        case 5:
            sellerdel(bas, count);
            break;
        case 6:
            sellerrecovery(bas, count);
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
    printf("(1)���Ե��(2)������ü����\n(3)���Լ���(4)���԰˻�\n(5)���Ի���(6)���Ժ���\n");
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

    bas[count].del = 0; //�߰��ϱ� 
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
void sellerlook(struct basic bas[], int count)
{
    int i;
    printf("********������ü��ȸâ�Դϴ�*****\n");
    for (i = 0; i < count; i++)
    {
        if (bas[i].del == 1)
        {
            continue;
        }
        else
        {
            printf("%5s%10s%20d-%d\n", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
        }
    }
}
void sellerupdate(struct basic bas[], int count)
{
    int number, i;

    printf("������ ���Թ�ȣ�� �Է����ּ���\n:");
    scanf("%d", &number);

    for (i = 0; i < count; i++)
    {
        if (i == number)
        {
            if (bas[i].del == 1) 
            {
                printf("�̹� ������ �����Դϴ�.\n");
            }
            else {
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

}
void sellersh(struct basic bas[], int count)
{
    int count1 = 0, i;
    char name[100];

    printf("�˻��� �����̸��� �Է����ּ���\n:");
    scanf("%s", name);

    for (i = 0; i < count; i++)
    {
        if (!strcmp(name, bas[i].name))
        {
            if (bas[i].del == 1)
            {
                printf("������ �����Դϴ�.\n");
                count1 = 1;
            }
            else
            {
                printf("%s %10s %20d-%d", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
                printf("�����մϴ�.\n");
                count1 = 1;
            }
        }
        else if(i == count - 1 && count1 == 0)
        {
            printf("ã���ô� ���԰� �����ϴ�.");
        }
    }
}

void sellerdel(struct basic bas[], int count)
{
    int number, count1 = 0 , i, j;

    
    printf("�ڹ���� ������\n **�����̺�Ʈ��**\n");
    printf("---------------------------\n");
    printf("������ ���Թ�ȣ�� �Է����ּ���\n:");
    scanf("%d", &number);

    for (i = 0; i < count; i++)
    {
        if (i == number)
        {
            if (bas[i].del == 1)
            {
                printf("�̹� ������ ���� �Դϴ�.\n");
                count1 = 1;
            }
            else
            {
            bas[i].del = 1;
            count1 = 1;
            }
        }
        else if(i == count - 1 && count1 == 0)
        {
            printf("ã���ô� ���԰� �����ϴ�.");

        }
    }
}

void sellerrecovery(struct basic bas[], int count)
{
    int choice = 0, number = 0;

    while (1)
    {
        //��ϵ� ���� ���� ��� 
        printf("�����Ϸ��� ���Թ�ȣ�� �Է����ּ���: ");
        scanf("%d", &number);
        for (int i = 0; i < count; i++)
        {
            if (i == number)
            {
                if (bas[i].del == 0)
                {
                    printf("������ ���԰� �ƴմϴ�.\n");
                }
                else
                {
                    printf("%s %10s %20d-%d\n", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
                    bas[i].del = 0;
                    printf("%s ���԰� �����Ǿ����ϴ�.\n", bas[i].name);
                    break;
                }
            }
            else if (i == count - 1) //�� ã�ƺ��� ������� 
            {
                printf("�����Ϸ��� ���Ը� ã������ �����ϴ�. \n");
                break;
            }
        }
    break;
}
}void sampledata(struct basic bas[])
{
    strcpy(bas[0].name ,"�׳�");
    strcpy(bas[0].add, "�뿬��");
    bas[0].num = 12314;
    bas[0].nums = 11444;
    bas[0].del = 0;

    strcpy(bas[1].name, "����");
    strcpy(bas[1].add, "��õ��");
    bas[1].num = 55555;
    bas[1].nums = 77777;
    bas[1].del = 0;

    strcpy(bas[2].name, "����");
    strcpy(bas[2].add, "����");
    bas[2].num = 888888;
    bas[2].nums = 999999;
    bas[2].del = 0;

    strcpy(bas[3].name, "����");
    strcpy(bas[3].add, "�뿬");
    bas[3].num = 222222222;
    bas[3].nums = 666666666;
    bas[3].del = 0;
}