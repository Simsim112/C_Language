#include <stdio.h>
#include <string.h>

int main() {

	FILE* file;
	int date;
	int null_check;
	char local[50];
	int time;
	char weather[50];
	file = fopen("weather.dat", "r");

	if (file == NULL) {
		printf("������ ���� ���߽��ϴ�.");
		return 1;
	}

	while (1) {
		fread(&date, sizeof(int), 1, file);
		if (feof(file) != 0)
			break;

		fprintf(stdout, "��¥: %d \n", date);
	}
	fclose(file);
	puts("�Է��� �Ϸ�Ǿ����ϴ�.");
	return 0;

}