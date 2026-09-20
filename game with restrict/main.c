#include <stdio.h>

int func(int *restrict a, int *restrict b) {
	*a = 10;
	*b = 20;
	return *a;
}

int main(void) {
	int x=0;

	printf("%d\n", func(&x, &x));
}
