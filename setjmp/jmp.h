#ifndef P_JMP_H
#define P_JMP_H

#include <stdint.h>

typedef struct {
	uint64_t RBX;
	uint64_t RBP;
	uint64_t R12;
	uint64_t R13;
	uint64_t R14;
	uint64_t R15;
	uint64_t RSP;
	uint64_t RIP;
} jmp_buf[1];

int setjmp(jmp_buf env);

__attribute__((noreturn))
void longjmp(jmp_buf env, int value);


#endif /* P_JMP_H */
