#include <stdio.h>
#include <string.h>

int main() {

	FILE* file;
	int date;
	int null_check;
	char local[50];
	int time;
	char weather[50];
	file = fopen("weather.dat", "w+");

	if (file == NULL) {
		printf("������ ���� ���߽��ϴ�.");
		return 1;
	}

	while (1) {
		fputs("��¥:", stdout);
		null_check = scanf("%d", &date);
		getchar();
		if (null_check == EOF)
			break;
		fwrite(&date, sizeof(int), 1, file);

		fputs("����: ", stdout);
		fgets(local, 50, stdin);
		fputs(local, file);

		fputs("����/����: ", stdout);
		time = fgetc(stdin);
		fputc(time, file);
		getchar();

		fputs("����: ", stdout);
		fgets(weather, 100, stdin);
		fputs(weather, file);

		fputs("\n", stdout);
	}
	fclose(file);
	puts("�Է��� �Ϸ�Ǿ����ϴ�.");
	return 0;

}