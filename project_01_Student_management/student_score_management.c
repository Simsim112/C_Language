#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print_out();
void print_out2();
void print_out3();
void printf_out4();

int main() {
	int i, j, k, temp, choice1, choice2, subject = 4, pass; //���� 1, 2, ����, �����Ǿ� ������ ����
	int student = 10, student_now = 3, student_add, student_del = 0; // �� �л��� , ��ϵ� �л� ��, �߰�, ������ �л� �� 
	char re_name[10], re_name2[10]; //�л��̸� ã�� , �̸� ����
	int sum[10];
	float average[10], temp_f;
	int rank[10];
	bool trash[10] = { 0 };

	char name[10][20] = //�л��̸�
	{
		"������","�󸶹�", "ȣȣȣ",
	};

	int score[10][4] = //����, ����, ����, ����
	{
		{10,20,30,48 }, {11,22,31,45 }, {10,20,30,48},
	};

	while (1) {
		//���� ���  ���� �ʱ�ȭ
		for (i = 0; i < student_now; i++)
		{
			sum[i] = 0;
			average[i] = 0;
			rank[i] = 0;
		}
		pass = 0;
		rank[0] = 1;

		//���� ��� ���
		for (i = 0; i < student_now; i++)
		{
			for (j = 0; j < subject; j++)//����
			{
				sum[i] += score[i][j];
			}
			average[i] = (float)sum[i] / subject; //���
		}
		print_out();
		scanf("%d", &choice1);
		switch (choice1)
		{
			while (1)
			{	//�л� ��� �� ���� 
		case 1:
			print_out2();
			scanf("%d", &choice2);
			switch (choice2)
			{
				//�л� ��� 
			case 1:
				printf("���� ��ϵ� �л� �� %d\n", student_now);
				for (int i = 0; i < student; i++)
				{
					if (trash[i] == 1)
						printf("���� �������� ������ �л��� %d�� �ֽ��ϴ�.\n", student_del);
				}
				printf("����� �л����� �Է����ּ���: ");
				scanf("%d", &student_add);
				if (student_add > 10)				//10�� �ʰ� �Է½� 
				{
					printf("����� �л����� �ʹ� �����ϴ�. \n");
					printf("�ִ� %d�� ��� �����մϴ�.\n\n", student);
				}
				else if (student_now + student_add <= 10) //���� ��ϵ� �ο����� 10�� �̳�
				{
					for (int i = student_now; i < student_now + student_add; i++)
					{
						printf("�߰��� �л� �̸��� �Է��ϼ���: ");
						scanf("%s", re_name);
						strcpy(name[i], re_name);
					};
					printf("�� %d���� �л��� �߰��Ǿ����ϴ�.\n\n", student_add);
					student_now += student_add;
				}
				else //��ϰ����ο� �ʰ��� 
					printf("���� ��ϰ����� �ο� %d���Դϴ�.\n\n", abs(student - student_now));
				break;
				//�л� �̸� ���� 
			case 2:
				printf("������ �л����� �Է��ϼ���: ");
				scanf("%s", re_name);
				for (i = 0; i < student; i++)
				{
					if (!strcmp(name[i], re_name) && trash[i] == 1)
					{
						printf("���л��� ���� ������ �����Դϴ�.\n");
						break;
					}
					else if (!strcmp(name[i], re_name))
					{
						printf("%s�� �ش��ϴ� �л��� ã�ҽ��ϴ�.\n", re_name);
						printf("������ �̸��� �Է��ϼ���: ");
						scanf("%s", re_name2);
						strcpy(name[i], re_name2);
						printf("%s ����  %s�� ����Ǿ����ϴ�.\n\n", re_name, name[i]);
						break;
					}
					else if (i == student - 1)
					{
						printf("%s �� �ش��ϴ� �л����� �����ϴ�.\n\n", re_name);
					}
				}
				break;
				//�л� ����
			case 3:
				printf("������ �л����� �Է��ϼ���: ");
				scanf("%s", re_name);
				for (i = 0; i < student; i++)
				{
					if (!strcmp(name[i], re_name) && trash[i] == 1)
					{
						printf("���л��� ���� ������ �����Դϴ�.\n");
						break;
					}
					else if (!strcmp(name[i], re_name))
					{
						printf("%s�� �ش��ϴ� �л��� ã�ҽ��ϴ�.\n", re_name);
						printf("�����Ϸ��� �ٽ��ѹ� �л����� �Է��ϼ���: ");
						scanf("%s", re_name2);
						if (!strcmp(name[i], re_name2))
						{
							trash[i] = 1;
							student_del += 1;
							printf("%s�� �ش��ϴ� �л��� �����Ǿ����ϴ�.\n\n", re_name);
						}
						else
						{
							printf("�����Ϸ��� �л��̸��� Ʋ���ϴ�.\n\n");
						}
						break;
					}
					else if (i == student - 1)
					{
						printf("%s �� �ش��ϴ� �л����� �����ϴ�.\n\n", re_name);
					}
				}
				break;
			case 4:
				break;
			default:
				printf("1~4������ ���� �Է����ּ���\n\n");
				break;
			}
			if (choice2 == 4)
				break;
			}
			break;
			while (1)
			{	//���� ��� �� ���� 
		case 2:
			print_out3();
			scanf("%d", &choice2);
			switch (choice2)
			{
				//���� ��� 
			case 1:
				if (student_now == 0)
				{
					printf("���� ��ϵ� �л��� �����ϴ�.\n\n");
				}
				else
					for (i = 0; i < student_now; i++)
					{
						if (trash[i] == 1)
							i++;
						printf("%s�л��� ������ �Է��ϼ���\n", name[i]);
						for (j = 0; j < subject; j++)
						{
							switch (j)
							{
							case 0: //������� ���� 
								printf("������� ������ �Է����ּ���: ");
								scanf("%d", &score[i][j]);
								break;
							case 1: //������� ���� 
								printf("������� ������ �Է����ּ���: ");
								scanf("%d", &score[i][j]);
								break;
							case 2: //���а��� ���� 
								printf("���а��� ������ �Է����ּ���: ");
								scanf("%d", &score[i][j]);
								break;
							case 3: //���а��� ���� 
								printf("���а��� ������ �Է����ּ���: ");
								scanf("%d", &score[i][j]);
								break;
							}
						}
						printf("\n");
					}
				break;
				//�л� ���� ����
			case 2:
				printf("������ ������ �л����� �Է��ϼ���: ");
				scanf("%s", re_name);
				for (i = 0; i < student; i++)
				{
					if (!strcmp(name[i], re_name) && trash[i] == 1)
					{
						printf("���л��� ���� ������ �����Դϴ�.\n\n");
						break;
					}
					else if (!strcmp(name[i], re_name))
					{
						printf("%s�� �ش��ϴ� �л��� ã�ҽ��ϴ�.\n", re_name);
						printf("%s �л��� ������ ������ �Է��ϼ���: \n", name[i]);
						printf("(1)���� \n");
						printf("(2)���� \n");
						printf("(3)���� \n");
						printf("(4)���� \n");
						scanf("%d", &choice2);
						switch (choice2)
						{
						case 1: //������� ���� 
							printf("������� ������ �Է����ּ���: ");
							scanf("%d", &score[i][0]);
							break;
						case 2: //������� ���� 
							printf("������� ������ �Է����ּ���: ");
							scanf("%d", &score[i][1]);
							break;
						case 3: //���а��� ���� 
							printf("���а��� ������ �Է����ּ���: ");
							scanf("%d", &score[i][2]);
							break;
						case 4: //���а��� ���� 
							printf("���а��� ������ �Է����ּ���: ");
							scanf("%d", &score[i][3]);
							break;
						defalult:
							printf("1~4������ ���� �Է����ּ���\n");
							break;
						}
						break;
					}
					else if (i == student - 1)
					{
						printf("%s �� �ش��ϴ� �л����� �����ϴ�.\n", re_name);
					}
				}
				break;
			case 3:
				break;
			default:
				printf("1~3������ ���� �Է����ּ���\n\n");
				break;
			}
			if (choice2 == 3)
				break;
			}
			break;
			//�л��̸����� ���� ��ȸ �� ���
		case 3:
			printf("�л����� �Է��ϼ���: ");
			scanf("%s", re_name);
			for (i = 0; i < student; i++)
			{
				if (!strcmp(name[i], re_name) && trash[i] == 1)
				{
					printf("���л��� ���� ������ �����Դϴ�.\n\n");
					break;
				}
				else if (!strcmp(name[i], re_name))
				{
					printf("%s �л��� ������\n", re_name);
					printf("����	����	����	����\n");
					for (j = 0; j < subject; j++)
					{
						printf("%d	", score[i][j]);
					}
					printf("\n\n");
					break;
				}
				else if (i == student - 1)
				{
					printf("%s �� �ش��ϴ� �л����� �����ϴ�.\n\n", re_name);
				}
			}
			break;
			//��ü �л��� ���������� ���
		case 4:
			for (i = student_now; i > 0; i--) //���ؼ� �̸� ����� ���� ��� �ٲ��ְ� ������� �ο�  
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

					//���� ���
					if (i == 0)
					{
						printf("%d", rank[0]);
					}
					else if (pass >= 1 && trash[i - 1] == 1)//�տ��� ���������� 
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
			printf("1~4�̳��� ���� �Է����ּ���\\nn");
			break;
		}
	}
	return 0;
}

void print_out() {
	printf("�л� ���� �ý��� �Դϴ�.\n");
	printf("���� �׸��� �����ϼ���\n");
	printf("(1) �л� ��� �� ����\n");
	printf("(2) ���� ��� �� ����\n");
	printf("(3) �л� �̸����� ���� ��ȸ �� ���\n");
	printf("(4) ��ü �л��� ���������� ���\n");
}
void print_out2() {
	printf("�л� ��� �� �����Դϴ�.\n");
	printf("(1)�л� ���\n");
	printf("(2)���� �л� ����\n");
	printf("(3)�л� ����\n");
	//printf("(4)�л� ����\n");
	printf("(4)���� �޴���..\n");
}
void print_out3() {
	printf("���� ��� �� �����Դϴ�.\n");
	printf("(1)���� ���\n");
	printf("(2)���� ���� ����\n");
	printf("(3)���� �޴���..\n");
}
void printf_out4() {
	printf("------------------------------------------------------------\n");
	printf("		�л����� ������ ���� ���\n");
	printf("------------------------------------------------------------\n");
	printf("�̸�	����	����	����	����	����	���	����\n");
	printf("------------------------------------------------------------\n");
}
