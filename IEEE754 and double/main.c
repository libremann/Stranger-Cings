#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define SET(n) x|=(uint64_t)1<<(n-1)

void print64(uint64_t x) {
    	for (int i = 63; i >= 0; i--) printf("%d", (int)((x >> i) & 1));
    	printf("\n");
}

int main() {
	uint64_t x=0;
	
	// SET(64);
	SET(63);
	SET(54);
	SET(52);
	SET(50);
	SET(48);

	print64(x);

	double X;
	memcpy(&X, &x, sizeof(double));

	printf("%f\n", (double)X);
}
