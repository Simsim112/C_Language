#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//문제 1
/*
int main(void) {
	float a, b;
	scanf("%f %f", &a, &b);
	printf("%.6f\n", a + b);
	printf("%.6f\n", a - b);
	printf("%.6f\n", a * b);
	printf("%.6f\n", a / b);
	return 0;
}
*/

//문제 1_2
/*
int main(void) {
	float r;
	scanf("%f", &r);
	printf("%f", r * r * 3.14);
	return 0;
}
*/

//문제 2
/*
void select(int *arr, int n);
void swap(int *arr, int *arr2);

int main(void) {
	int a[7];
	int sum = 0;
	for (int i = 0; i < 7; i++) {
		printf("정수형 데이터 입력:");
		scanf("%d",&a[i]);
		sum += a[i];
	}
	select(a, 7);

	printf("최대 값 : %d\n", a[6]);
	printf("최소 값: %d\n", a[0]);
	printf("전체합: %d\n", sum);
	printf("평 균 : %.6f", (float)sum / 7);
	return 0;
}

void select(int *arr,int n) {
	int min = 0;
	for (int i = 0;i < n ; i++) {
		min = i;
		for (int j = i + 1; j < n ; j++) {
			if (arr[min] > arr[j])
				min = j;
			swap(&arr[i], &arr[min]);
		}
	}
}

void swap(int *arr,int *arr2) {
	int tmp = 0;
	tmp = *arr;
	*arr = *arr2;
	*arr2 = tmp;
}
*/

//문제 3_1
/*
int main() {
	int a, b;
	int lar;
	printf("두 개의 숫자를 입력하세요:");
	scanf("%d %d", &a, &b);
	a > b ? (lar = a) : (lar = b);
	printf("큰 수는 : %d", lar);
	return 0;
}
*/

//문제 3_2
/*
int main() {
	int a, b, c;
	int lar;
	printf("세 개의 숫자를 입력하세요:");
	scanf("%d %d %d", &a, &b, &c);
	a > b ? a > c ? (lar = a) : (lar = c) : b > c ? (lar = b) : (lar = c);
	printf("큰 수는 : %d", lar);
	return 0;
}
*/

//문제 4_1
/*
int main() {
	int a;
	int sum = 0;
	while (1){
		printf("1이상의 정수 입력:");
		scanf("%d", &a);
		if (a >= 1) {
			for (int i = 1; i < a + 1; i++) {
				sum += i;
			}
			printf("1부터 %d까지의 합은: %d", a, sum);
			break;
		}
		else
			printf("1이상의 정수를 입력해야 합니다.\n");
	}
}
*/

//문제 4_2
/*
void swap(int *a, int *b);

int main() {
	int n1,n2;
	int sum = 0;

	printf("두 개의 정수 입력:");
	scanf("%d %d", &n1, &n2);
	if (n1 > n2)
		swap(&n1, &n2);
	for (int i = n1; i < n2 + 1; i++) {
		sum += i;
	}
	printf("%d과 %d을 포함하여 그 사이에 있는 정수들의 합 : %d", n1, n2, sum);
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
*/

//문제 5
/*
void swap(int *a, int *b);

int main() {
	int n1, n2;
	int sum = 0;
	printf("두 개의 정수 입력:");
	scanf("%d %d", &n1, &n2);
	if (n1 > n2)
		swap(&n1, &n2);
	for (int i = n1; i < n2 + 1; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			printf("%d는 합에서 제외\n", i);
		}
		else
			sum += i;
	}
	printf("%d과 %d을 포함하여 그 사이에 있는 정수들의 합 : %d", n1, n2, sum);
}

void swap(int *a, int *b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
*/

//문제 6_1
/*
int main() {
	int a = 0;
	int o_sum = 0;
	int a_sum = 0;

	do {
		printf("자연수 입력: ");
		scanf("%d", &a);
	} while (a <= 0);

	for (int i = 0; i < a + 1; i++) {
		if (i % 2 == 0)
			a_sum += i;
		else
			o_sum += i;
	}
	printf("%d이하 홀수 합: %d \n", a, o_sum);
	printf("%d이하 짝수 합: %d \n", a, a_sum);

	return 0;

}
*/

//문제 6_2
/*int main() {
	int n, n2;
	int pre_sum = 0;
	int sum = 0;
	do{
		printf("자연수 입력 : ");
		scanf("%d", &n);

	} while (n < 2);

	for (int i = 1; i < n; i++) {
		pre_sum += i;
		if (pre_sum > n) {
			n2 = i;
			sum = pre_sum;
			pre_sum -= i;
			break;
		}

	}
	printf("%d를 더할 때 처음 %d를 넘기 시작한다.\n", n2, n);
	printf("%d을 넘기 이전의 값 : %d \n", n, pre_sum);
	printf("%d을 넘은 이후의 값 : %d ", n , sum);
}*/

//문제 7_1
/*
int main(void) {
	int a;
	do {
		printf("홀수 단(1), 짝수 단(2) : ");
		scanf("%d", &a);
		if (a != 1 && a != 2) {
			printf("잘못된 입력입니다. 1또는 2만 입력하세요.\n");
		}
	} while (a != 1 && a != 2);

	if (a == 1) {
		for (int i = 1; i < 10; i += 2) {
			for (int j = 1; j < 10; j++)
				printf("%d x %d = %d\n", i, j, i * j);
		}
	}
	else {
		for (int i = 2; i < 10; i += 2) {
			for (int j = 1; j < 10; j++)
				printf("%d x %d = %d\n", i, j, i * j);
		}
	}

	return 0;
}
*/

//문제 7_2
/*int main(void) {
	int n;
	printf("정수 입력 : ");
	scanf("%d", &n);
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; k <= 100; k++) {
				if (i * j - k == n) {
					printf("%d x %d - %d = %d\n", i, j, k, n);
				}
			}
		}
	}
	return 0;
}*/

//문제 8
/*
void swap(int *arr, int *arr2);
void bubble(int *arr, int size);
void bubble2(int *arr, int size);

int main(void) {
	int a[5];
	int i;
	for (i = 0; i < 5; i++) {
		printf("숫자 %d 입력 : ", i);
		scanf("%d", &a[i]);
	}
	bubble2(&a, 5);
	for (i = 0; i < 5; i++) {
		printf("%d  ", a[i]);
	}
	return 0;
}
void bubble(int *arr, int size) {
	int i, j;
	for (i = size - 1; i > 0  ; i--) {
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}
void bubble2(int *arr, int size)
{
	int i,j;
	for (i = 0; i < size-1; i++)
	{
		for (j =  0; j < (size - i) - 1; j++) 
		{
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}
void swap(int *arr, int *arr2) {
	int temp;
	temp = *arr;
	*arr = *arr2;
	*arr2 = temp;
}
*/

//문제 9
/*
int main(void) {
	char a[50];
	int i;
	printf("문자열 입력: ");
	gets(a);
	for (i = 0; i < 49; i++) {
		char h = a[i];
		int ch = (int)a[i];
		
		if (65 <= ch && ch <= 90)
		{
			_strlwr(&h);
			printf("%c", h);
		}
		else if (97 <= ch && ch <= 122)
		{
			_strupr(&h);
			printf("%c", h);
		}
		else if (ch == 32)
			printf(" ");
		else if (ch == 0)
			break;
		else
			printf("%c", h);
	}
	return 0;
}
*/

//문제 10
/*
int total(int kor, int eng, int mat) {
	return kor + eng + mat;
}
double average(int tot) {
	double a = 3;
	return (double)tot / 3;
}
void print_title(void) {
	printf("	====< 성적표>====	\n");
	printf("                                \n");
	printf("---------------------------------------\n");
	printf("국어	영어	수학	총점	평균\n");
	printf("----------------------------------------\n");

}
int main(void) {
	int a, b, c;
	int result;
	double av;
	printf("세 과목의 점수 입력:");
	scanf("%d %d %d", &a, &b, &c);
	result = total(a, b, c);
	av = average(result);
	print_title();
	printf("%d	%d	%d	%d	%.1f", a, b, c, result, av);
}
*/

//문제 11
/*
int Factorial(int a) {
	int i = 0, sum = 1;
	for (i = 1; i <= a; i++) {
		sum *= i;
	}
	return sum;
}
int main(void) {
	int a = 0;
	do {
		printf("숫자 입력(1이상):");
		scanf("%d", &a);
		if (a < 1)
			printf("입력이 잘못되어 예상치 못한 결과를 얻었습니다.\n");
	} while (a < 1);
	printf("%d! = %d", a, Factorial(a));
	return 0;
}
*/
