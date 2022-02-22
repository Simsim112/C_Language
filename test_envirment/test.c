#include <stdio.h>


int main() {
	int* pa;
	int a;
	pa = &a;
	*pa = 10;
	printf("%d", *pa);
	return 0;
}

