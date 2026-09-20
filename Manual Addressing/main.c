#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
	int literal=123;

	int *p=&literal;
	int *q;
	
	intptr_t ip;

	printf("Address: %p\n", p);

	printf(">> ");
	scanf("%" SCNiPTR, &ip);

	q = (int *)ip;

	printf("%d\n", *q);
}
