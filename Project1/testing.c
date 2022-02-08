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

	printf("length of \"%s\":%d\n",a, stringLength(a));
	printf("length of \"%s\":%d\n\n\n", b, stringLength(b));
	stringCopy(a, copySt);
	printf("\n\n");
	stringCat(a, b);
	printf("\n\n");
	printf("compare a, a: %d\n",stringCompare(a, a));
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

	for (int i = 0; i < 100; i++)
	{
		if (dest[i] == NULL)
			break;
		else
		{
		source[i] = dest[i];
		Length1++;
		}
	}

	printf("copy string: \"");
	for (int i = 0; i < 100; i++)
	{
		if (i == Length1)
			break;
		else 
		{
			printf("%c", source[i]);
			Length2++;
		}
	}
	printf("\"\n");
	return Length2;

}

int stringCat(char* dest, char* source)
{
	int Length1 = 0,
		Length2 = 0;

	for (int i = 0; i < 100; i++)
	{
		if (dest[i] == NULL)
			break;
		else
			Length1++;
	}

	for (int i = 0; i < 100; i++)
	{
		if (source[i] == NULL)
			break;
		else 
		{
		dest[i + Length1] = source[i];
		Length2++;
		}
	}
	printf("concat string: \"");
	for (int i = 0; i < Length1 + Length2; i++)
	{
		printf("%c", dest[i]);
	}
	printf("\"\n");

	//배열 붙여줬기 때문에 원래 크기 찾으려고 초기화 
	for (int i = 0; i < 100; i++)
	{
		if (i == Length1)
		{
			dest[Length1] = NULL;
			break;
		}
		else
			dest[i] = dest[i];
	}

	return Length1 + Length2;

}

int stringCompare(char* str1, char* str2) 
{
	int same, 
		Length1 = 0, 
		Length2 = 0, 
		total_length = 0;

	for (int i = 0; i < 100; i++)
	{
		if (str1[i] == NULL)
			break;
		else
			Length1++;

	}

	for (int i = 0; i < 100; i++)
	{
		if (str2[i] == NULL)
			break;
		else
			Length2++;
	}

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