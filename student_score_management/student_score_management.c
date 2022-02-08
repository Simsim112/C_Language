#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print_out();
void print_out2();
void print_out3();
void printf_out4();

int main() {
	int i, j, k, temp, choice1, choice2, subject = 4, pass; //선택 1, 2, 과목, 삭제되어 지나간 개수
	int student = 10, student_now = 3, student_add, student_del = 0; // 총 학생수 , 등록된 학생 수, 추가, 삭제된 학생 수 
	char re_name[10], re_name2[10]; //학생이름 찾음 , 이름 변수
	int sum[10];
	float average[10], temp_f;
	int rank[10];
	bool trash[10] = { 0 };

	char name[10][20] = //학생이름
	{
		"가나다","라마바", "호호호",
	};

	int score[10][4] = //국어, 영어, 수학, 과학
	{
		{10,20,30,48 }, {11,22,31,45 }, {10,20,30,48},
	};

	while (1) {
		//총점 평균  순위 초기화
		for (i = 0; i < student_now; i++)
		{
			sum[i] = 0;
			average[i] = 0;
			rank[i] = 0;
		}
		pass = 0;
		rank[0] = 1;

		//총점 평균 계산
		for (i = 0; i < student_now; i++)
		{
			for (j = 0; j < subject; j++)//총점
			{
				sum[i] += score[i][j];
			}
			average[i] = (float)sum[i] / subject; //평균
		}
		print_out();
		scanf("%d", &choice1);
		switch (choice1)
		{
			while (1)
			{	//학생 등록 및 수정 
		case 1:
			print_out2();
			scanf("%d", &choice2);
			switch (choice2)
			{
				//학생 등록 
			case 1:
				printf("현재 등록된 학생 수 %d\n", student_now);
				for (int i = 0; i < student; i++)
				{
					if (trash[i] == 1)
						printf("현재 논리적으로 삭제된 학생이 %d명 있습니다.\n", student_del);
				}
				printf("등록할 학생수를 입력해주세요: ");
				scanf("%d", &student_add);
				if (student_add > 10)				//10명 초과 입력시 
				{
					printf("등록할 학생수가 너무 많습니다. \n");
					printf("최대 %d명 등록 가능합니다.\n\n", student);
				}
				else if (student_now + student_add <= 10) //새로 등록된 인원포함 10명 이내
				{
					for (int i = student_now; i < student_now + student_add; i++)
					{
						printf("추가할 학생 이름을 입력하세요: ");
						scanf("%s", re_name);
						strcpy(name[i], re_name);
					};
					printf("총 %d명의 학생이 추가되었습니다.\n\n", student_add);
					student_now += student_add;
				}
				else //등록가능인원 초과시 
					printf("현재 등록가능한 인원 %d명입니다.\n\n", abs(student - student_now));
				break;
				//학생 이름 수정 
			case 2:
				printf("수정할 학생명을 입력하세요: ");
				scanf("%s", re_name);
				for (i = 0; i < student; i++)
				{
					if (!strcmp(name[i], re_name) && trash[i] == 1)
					{
						printf("이학생은 현재 삭제된 상태입니다.\n");
						break;
					}
					else if (!strcmp(name[i], re_name))
					{
						printf("%s에 해당하는 학생을 찾았습니다.\n", re_name);
						printf("변경할 이름을 입력하세요: ");
						scanf("%s", re_name2);
						strcpy(name[i], re_name2);
						printf("%s 에서  %s로 변경되었습니다.\n\n", re_name, name[i]);
						break;
					}
					else if (i == student - 1)
					{
						printf("%s 에 해당하는 학생명이 없습니다.\n\n", re_name);
					}
				}
				break;
				//학생 삭제
			case 3:
				printf("삭제할 학생명을 입력하세요: ");
				scanf("%s", re_name);
				for (i = 0; i < student; i++)
				{
					if (!strcmp(name[i], re_name) && trash[i] == 1)
					{
						printf("이학생은 현재 삭제된 상태입니다.\n");
						break;
					}
					else if (!strcmp(name[i], re_name))
					{
						printf("%s에 해당하는 학생을 찾았습니다.\n", re_name);
						printf("삭제하려면 다시한번 학생명을 입력하세요: ");
						scanf("%s", re_name2);
						if (!strcmp(name[i], re_name2))
						{
							trash[i] = 1;
							student_del += 1;
							printf("%s에 해당하는 학생이 삭제되었습니다.\n\n", re_name);
						}
						else
						{
							printf("삭제하려는 학생이름이 틀립니다.\n\n");
						}
						break;
					}
					else if (i == student - 1)
					{
						printf("%s 에 해당하는 학생명이 없습니다.\n\n", re_name);
					}
				}
				break;
			case 4:
				break;
			default:
				printf("1~4사이의 값을 입력해주세요\n\n");
				break;
			}
			if (choice2 == 4)
				break;
			}
			break;
			while (1)
			{	//성적 등록 및 수정 
		case 2:
			print_out3();
			scanf("%d", &choice2);
			switch (choice2)
			{
				//성적 등록 
			case 1:
				if (student_now == 0)
				{
					printf("현재 등록된 학생이 없습니다.\n\n");
				}
				else
					for (i = 0; i < student_now; i++)
					{
						if (trash[i] == 1)
							i++;
						printf("%s학생의 점수를 입력하세요\n", name[i]);
						for (j = 0; j < subject; j++)
						{
							switch (j)
							{
							case 0: //국어과목 변경 
								printf("국어과목 성적을 입력해주세요: ");
								scanf("%d", &score[i][j]);
								break;
							case 1: //영어과목 변경 
								printf("영어과목 성적을 입력해주세요: ");
								scanf("%d", &score[i][j]);
								break;
							case 2: //수학과목 변경 
								printf("수학과목 성적을 입력해주세요: ");
								scanf("%d", &score[i][j]);
								break;
							case 3: //과학과목 변경 
								printf("과학과목 성적을 입력해주세요: ");
								scanf("%d", &score[i][j]);
								break;
							}
						}
						printf("\n");
					}
				break;
				//학생 성적 수정
			case 2:
				printf("성적을 수정할 학생명을 입력하세요: ");
				scanf("%s", re_name);
				for (i = 0; i < student; i++)
				{
					if (!strcmp(name[i], re_name) && trash[i] == 1)
					{
						printf("이학생은 현재 삭제된 상태입니다.\n\n");
						break;
					}
					else if (!strcmp(name[i], re_name))
					{
						printf("%s에 해당하는 학생을 찾았습니다.\n", re_name);
						printf("%s 학생의 변경할 과목을 입력하세요: \n", name[i]);
						printf("(1)국어 \n");
						printf("(2)영어 \n");
						printf("(3)수학 \n");
						printf("(4)과학 \n");
						scanf("%d", &choice2);
						switch (choice2)
						{
						case 1: //국어과목 변경 
							printf("국어과목 성적을 입력해주세요: ");
							scanf("%d", &score[i][0]);
							break;
						case 2: //영어과목 변경 
							printf("영어과목 성적을 입력해주세요: ");
							scanf("%d", &score[i][1]);
							break;
						case 3: //수학과목 변경 
							printf("수학과목 성적을 입력해주세요: ");
							scanf("%d", &score[i][2]);
							break;
						case 4: //과학과목 변경 
							printf("과학과목 성적을 입력해주세요: ");
							scanf("%d", &score[i][3]);
							break;
						defalult:
							printf("1~4까지의 값을 입력해주세요\n");
							break;
						}
						break;
					}
					else if (i == student - 1)
					{
						printf("%s 에 해당하는 학생명이 없습니다.\n", re_name);
					}
				}
				break;
			case 3:
				break;
			default:
				printf("1~3사이의 값을 입력해주세요\n\n");
				break;
			}
			if (choice2 == 3)
				break;
			}
			break;
			//학생이름으로 성적 조회 후 출력
		case 3:
			printf("학생명을 입력하세요: ");
			scanf("%s", re_name);
			for (i = 0; i < student; i++)
			{
				if (!strcmp(name[i], re_name) && trash[i] == 1)
				{
					printf("이학생은 현재 삭제된 상태입니다.\n\n");
					break;
				}
				else if (!strcmp(name[i], re_name))
				{
					printf("%s 학생의 성적은\n", re_name);
					printf("국어	영어	수학	과학\n");
					for (j = 0; j < subject; j++)
					{
						printf("%d	", score[i][j]);
					}
					printf("\n\n");
					break;
				}
				else if (i == student - 1)
				{
					printf("%s 에 해당하는 학생명이 없습니다.\n\n", re_name);
				}
			}
			break;
			//전체 학생을 성적순으로 출력
		case 4:
			for (i = student_now; i > 0; i--) //비교해서 이름 과목명 총점 평균 바꿔주고 순서대로 부여  
			{
				for (j = 0; j < i - 1; j++)
				{
					if (sum[j] < sum[j + 1])
					{
						temp = sum[j];
						sum[j] = sum[j + 1];
						sum[j + 1] = temp;

						strcpy(re_name, name[j]);
						strcpy(name[j], name[j + 1]);
						strcpy(name[j + 1], re_name);

						temp_f = average[j];
						average[j] = average[j + 1];
						average[j + 1] = temp_f;


						for (int k = 0; k < subject; k++)
						{
							temp = score[j][k];
							score[j][k] = score[j + 1][k];
							score[j + 1][k] = temp;
						}
					}
				}

			}
			printf_out4();
			for (i = 0; i < student_now; i++)
			{
				if (trash[i] == 1)
				{
					++pass;
					continue;
				}
				else
				{
					printf("%s	", name[i]);
					for (j = 0; j < subject; j++)
					{
						printf("%d	", score[i][j]);
					}
					printf("%d	", sum[i]);
					printf("%.1f	", average[i]);

					//순위 계산
					if (i == 0)
					{
						printf("%d", rank[0]);
					}
					else if (pass >= 1 && trash[i - 1] == 1)//앞에꺼 지워졌을때 
					{
						if (i - pass == 0)
						{
							rank[i] = 1;
						}
						else if (sum[i - (1 + pass)] == sum[i])
						{
							rank[i] = rank[i + (1 + pass)];
						}
						else
						{
							rank[i] = rank[i - (1 + pass)] + 1;
						}
						printf("%d", rank[i]);
					}
					else if (sum[i - 1] == sum[i])
					{
						rank[i] = rank[i - 1];
						printf("%d", rank[i]);
					}
					else
					{
						rank[i] = rank[i - 1] + 1;
						printf("%d.", rank[i]);
					}
				}
				printf("\n");
			}
			printf("\n");
			break;
		default:
			printf("1~4이내의 값을 입력해주세요\\nn");
			break;
		}
	}
	return 0;
}

void print_out() {
	printf("학생 관리 시스템 입니다.\n");
	printf("관리 항목을 선택하세요\n");
	printf("(1) 학생 등록 및 수정\n");
	printf("(2) 성적 등록 및 수정\n");
	printf("(3) 학생 이름으로 성적 조회 후 출력\n");
	printf("(4) 전체 학생을 성적순으로 출력\n");
}
void print_out2() {
	printf("학생 등록 및 수정입니다.\n");
	printf("(1)학생 등록\n");
	printf("(2)기존 학생 수정\n");
	printf("(3)학생 삭제\n");
	//printf("(4)학생 복구\n");
	printf("(4)상위 메뉴로..\n");
}
void print_out3() {
	printf("성적 등록 및 수정입니다.\n");
	printf("(1)성적 등록\n");
	printf("(2)기존 성적 수정\n");
	printf("(3)상위 메뉴로..\n");
}
void printf_out4() {
	printf("------------------------------------------------------------\n");
	printf("		학생들의 성적순 성적 결과\n");
	printf("------------------------------------------------------------\n");
	printf("이름	국어	영어	수학	과학	총점	평균	석차\n");
	printf("------------------------------------------------------------\n");
}
