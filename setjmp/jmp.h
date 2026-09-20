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

/*
int setjmp(jmp_buf env) {
	// We can't move RIP directly. When a function is called,
	 * the address of the next instruction is pushed onto the top of the stack.
	 // __asm__(
			"lea 8(%%rsp), %%rax\n" 
			"mov %%rax, %0\n"
			: "=m"(env->RIP)
			:
			: "rax"
		);
	
	__asm__("mov %%rbx, %0\n" : "=m"(env->RBX));
	__asm__("mov %%rbp, %0\n" : "=m"(env->RBP));
	__asm__("mov %%r12, %0\n" : "=m"(env->R12));
	__asm__("mov %%r13, %0\n" : "=m"(env->R13));
	__asm__("mov %%r14, %0\n" : "=m"(env->R14));
	__asm__("mov %%r15, %0\n" : "=m"(env->R15));
	__asm__(
		"lea 8(%%rsp), %%rax\n"
		"mov %%rax, %0\n"
		: "=m"(env->RSP)
		:
		: "rax");

	return 0;
}
*/


#endif /* P_JMP_H */
