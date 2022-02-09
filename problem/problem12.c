#include <stdio.h>
#include <string.h> //쓰지말고

int stringLength(char* str);
int stringCopy(char* dest, char* source);
int stringCat(char* dest, char* source);
int stringCompare(char* str1, char* str2);

int main()
{
	char a[100] = "hello.";
	char b[100] = "nice to meet you.";
	char copySt[100];

	printf("length of \"%s\":%d\n", a, stringLength(a));
	printf("length of \"%s\":%d\n\n\n", b, stringLength(b));

	stringCopy(a, copySt);
	printf("copy string: \"%s\"\n\n\n", copySt);

	stringCat(copySt, b);
	printf("Cat string: \"%s\"\n\n\n", copySt);

	printf("compare a, a: %d\n", stringCompare(a, a));
	printf("compare b, b: %d\n", stringCompare(b, b));
	printf("compare a, b: %d\n", stringCompare(a, b));
	printf("compare b, a: %d\n", stringCompare(b, a));
	return 0;
}

int stringLength(char* str)
{
	int Length = 0;

	for (int i = 0; i < 100; i++)
	{
		if (str[i] == NULL)
			break;
		else
			Length++;
	}

	return Length;

}

int stringCopy(char* dest, char* source)
{
	int Length1 = 0,
		Length2 = 0;

	Length1 = stringLength(dest) + 1; //문자 끝나는 NULL값 추가 
	for (int i = 0; i < Length1; i++)
	{
		source[i] = dest[i];
	}
	Length2 = stringLength(source);

	return Length2;

}

int stringCat(char* dest, char* source)
{
	int Length1 = 0,
		Length2 = 0;

	Length1 = stringLength(dest);
	Length2 = stringLength(source) + 1; //문자 끝나는 NULL값 추가 

	for (int i = 0; i < Length2; i++)
	{
		dest[i + Length1] = source[i];
	}

	return Length1 + Length2;

}

int stringCompare(char* str1, char* str2)
{
	int same,
		Length1 = 0,
		Length2 = 0,
		total_length = 0;

	Length1 = stringLength(str1);

	Length2 = stringLength(str2);

	total_length = (Length2 >= Length1 ? Length2 : Length1);

	for (int i = 0; i < 100; i++)
	{
		if (i == total_length)
			break;
		else if (str1[i] == str2[i])
			same = 1;
		else
			same = 0;
	}

	return same;

}