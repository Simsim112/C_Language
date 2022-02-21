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
		printf("파일을 열지 못했습니다.");
		return 1;
	}

	while (1) {
		fread(&date, sizeof(int), 1, file);
		if (feof(file) != 0)
			break;

		fprintf(stdout, "날짜: %d \n", date);
	}
	fclose(file);
	puts("입력이 완료되었습니다.");
	return 0;

}