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

/*메뉴관련함수*/
int Menu1();
void moveMenu();

struct basic
{
    char name[20], add[20];
    int del, num, nums;

}bas[100] = { 0, }; //구조체정의


/*메인함수*/
void main()
{
    sampledata(bas);
    int i = 0;
    int count = 4; // 숫자카운터  

    while (1)
    {


        int Menu = Menu1(); //메뉴관련 함수

        switch (Menu) {
        case 1: //가게등록
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
    printf(" **      ****         ★배달의 무성★   \n");
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


    printf("★배달의 무성★\n **오픈이벤트중**\n");
    printf("---------------------------\n");
    printf("(1)가게등록(2)가게전체보기\n(3)가게수정(4)가게검색\n(5)가게삭제(6)가게복구\n");
    printf("이동하실 번호를 입력해주세요\n");
    printf("---------------------------\n");


    scanf("%d", &mainmenu);


    return mainmenu;
}


void moveMenu()
{
    printf("\n계속하시려면 엔터키를 누르세요.\n");
    getch();
}

void selleradd(struct basic bas[], int count)
{
    char names[100];
    char adds[100];

    bas[count].del = 0; //추가하기 
    printf("가게를 등록해주세요!\n");
    scanf("%s", names);
    strcpy(bas[count].name, names);

    printf("주소를 등록해주세요!\n");
    scanf("%s", adds);
    strcpy(bas[count].add, adds);

    printf("전화번호를 입력해주세요!\n");
    scanf("%d%d", &bas[count].num, &bas[count].nums);

    printf("%s : %s :%d-%d,%d", bas[count].name, bas[count].add, bas[count].num, bas[count].nums, count);
    moveMenu();

}
void sellerlook(struct basic bas[], int count)
{
    int i;
    printf("********가게전체조회창입니다*****\n");
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

    printf("수정할 가게번호를 입력해주세요\n:");
    scanf("%d", &number);

    for (i = 0; i < count; i++)
    {
        if (i == number)
        {
            if (bas[i].del == 1) 
            {
                printf("이미 삭제된 가게입니다.\n");
            }
            else {
                printf("수정하실 상호명(공백없이)을 입력해주세요:\n");
                scanf("%s", &bas[i].name);
                printf("주소를입력해주세요\n");
                scanf("%s", &bas[i].add);
                printf("전화번호를입력해주세요.\n");
                scanf("%d%d", &bas[i].num, &bas[i].nums);

                printf("%s %s %d-%d가 수정되었습니다(%d).", bas[i].name, bas[i].add, bas[i].num, bas[i].nums, count);
            }
        }
    }

}
void sellersh(struct basic bas[], int count)
{
    int count1 = 0, i;
    char name[100];

    printf("검색할 가게이름을 입력해주세요\n:");
    scanf("%s", name);

    for (i = 0; i < count; i++)
    {
        if (!strcmp(name, bas[i].name))
        {
            if (bas[i].del == 1)
            {
                printf("삭제된 가게입니다.\n");
                count1 = 1;
            }
            else
            {
                printf("%s %10s %20d-%d", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
                printf("감사합니다.\n");
                count1 = 1;
            }
        }
        else if(i == count - 1 && count1 == 0)
        {
            printf("찾으시는 가게가 없습니다.");
        }
    }
}

void sellerdel(struct basic bas[], int count)
{
    int number, count1 = 0 , i, j;

    
    printf("★배달의 무성★\n **오픈이벤트중**\n");
    printf("---------------------------\n");
    printf("삭제할 가게번호를 입력해주세요\n:");
    scanf("%d", &number);

    for (i = 0; i < count; i++)
    {
        if (i == number)
        {
            if (bas[i].del == 1)
            {
                printf("이미 삭제된 가게 입니다.\n");
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
            printf("찾으시는 가게가 없습니다.");

        }
    }
}

void sellerrecovery(struct basic bas[], int count)
{
    int choice = 0, number = 0;

    while (1)
    {
        //등록된 고객이 있을 경우 
        printf("복구하려는 가게번호를 입력해주세요: ");
        scanf("%d", &number);
        for (int i = 0; i < count; i++)
        {
            if (i == number)
            {
                if (bas[i].del == 0)
                {
                    printf("삭제된 가게가 아닙니다.\n");
                }
                else
                {
                    printf("%s %10s %20d-%d\n", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
                    bas[i].del = 0;
                    printf("%s 가게가 복구되었습니다.\n", bas[i].name);
                    break;
                }
            }
            else if (i == count - 1) //다 찾아봐도 없을경우 
            {
                printf("삭제하려는 가게를 찾을수가 없습니다. \n");
                break;
            }
        }
    break;
}
}void sampledata(struct basic bas[])
{
    strcpy(bas[0].name ,"네네");
    strcpy(bas[0].add, "대연동");
    bas[0].num = 12314;
    bas[0].nums = 11444;
    bas[0].del = 0;

    strcpy(bas[1].name, "교촌");
    strcpy(bas[1].add, "남천동");
    bas[1].num = 55555;
    bas[1].nums = 77777;
    bas[1].del = 0;

    strcpy(bas[2].name, "피자");
    strcpy(bas[2].add, "서면");
    bas[2].num = 888888;
    bas[2].nums = 999999;
    bas[2].del = 0;

    strcpy(bas[3].name, "피자");
    strcpy(bas[3].add, "대연");
    bas[3].num = 222222222;
    bas[3].nums = 666666666;
    bas[3].del = 0;
}