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
		printf("파일을 열지 못했습니다.");
		return 1;
	}

	while (1) {
		fputs("날짜:", stdout);
		null_check = scanf("%d", &date);
		getchar();
		if (null_check == EOF)
			break;
		fwrite(&date, sizeof(int), 1, file);

		fputs("지역: ", stdout);
		fgets(local, 50, stdin);
		fputs(local, file);

		fputs("오전/오후: ", stdout);
		time = fgetc(stdin);
		fputc(time, file);
		getchar();

		fputs("날씨: ", stdout);
		fgets(weather, 100, stdin);
		fputs(weather, file);

		fputs("\n", stdout);
	}
	fclose(file);
	puts("입력이 완료되었습니다.");
	return 0;

}