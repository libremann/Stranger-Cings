.section .text
.global longjmp

longjmp:
    mov (%rdi)  , %rbx
    mov 8(%rdi) , %rbp
    mov 16(%rdi), %r12
    mov 24(%rdi), %r13
    mov 32(%rdi), %r14
    mov 40(%rdi), %r15

    mov 56(%rdi), %rdx

    mov 48(%rdi), %rsp

    mov %rsi, %rax
    jmp *%rdx