#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

int main() {
	char temp[100];
	char* str[5];


	for (int i = 0; i < 5; i++) {
		printf("���� �Է����ּ���:");
		gets(temp);
		str[i] = (char *)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
	}

	for (int i = 0; i < 5; i++) {
		printf("%s\n", str[i]);
	}
}