#include <stdio.h>
#include <string.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS

void selleradd(struct basic bas[], int count, int i);
void sellerlook(struct basic bas[], int count, int i);
void sellerupdate(struct basic bas[], int count, int i);
void sellersh(struct basic bas[], int count, int i);
void del(struct basic bas[], int count, int i);

/*메뉴관련함수*/
int Menu1();
void moveMenu();

struct basic
{
    char name[20], add[20];
    int num, nums;

}bas[100]; //구조체정의


/*메인함수*/
void main()
{
    int i = 0;
    int count = 0; // 숫자카운터  

    while (1)
    {


        int Menu = Menu1(); //메뉴관련 함수

        switch (Menu) {
        case 1: //가게등록
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
    printf("(1)가게등록(2)가게전체보기\n(3)가게수정\n(4)가게검색\n(5)가게삭제\n");
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
void sellerlook(struct basic bas[], int count, int i)
{

    printf("********가게전체조회창입니다*****\n");
    for (i = 0; i < count; i++)
    {
        printf("%5s%10s%20d-%d\n", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);

    }
    printf("감사합니다.");


}
void sellerupdate(struct basic bas[], int count, int i)
{
    char names[100];

    printf("수정할 가게를 입력해주세요\n:");
    scanf("%s", names);

    for (i = 0; i < count; i++)
    {
        if ((!strcmp(names, &bas[i].name)))
        {
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
void sellersh(struct basic bas[], int count, int i)
{
    char names[100];

    printf("검색할 가게를 입력해주세요\n:");
    scanf("%s", names);

    for (i = 0; i < count; i++)
    {
        if ((!strcmp(names, bas[i].name)))
        {
            printf("%s %10s %20d-%d", bas[i].name, bas[i].add, bas[i].num, bas[i].nums);
            printf("감사합니다.");
        }
        else
        {
            printf("찾으시는 가게가 없습니다.");
        }
    }
}

void del(struct basic bas[], int count, int i)
{
    int j;
    char names[20];

    printf("★배달의 무성★\n **오픈이벤트중**\n");
    printf("---------------------------\n");
    printf("삭제할 가게를 입력해주세요\n:");
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
            printf("찾으시는 가게가 없습니다.");
    }
    count--;
}