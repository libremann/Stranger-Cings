.section .text
.global setjmp

setjmp:
    mov %rbx, (%rdi)
    mov %rbp, 8(%rdi)
    mov %r12, 16(%rdi)
    mov %r13, 24(%rdi)
    mov %r14, 32(%rdi)
    mov %r15, 40(%rdi)

    // call decrements RSP by 8; undo that to get the caller's RSP
    lea 8(%rsp), %rax
    mov %rax, 48(%rdi)

    // call saved next instruct address on stack
    mov (%rsp), %rax
    mov %rax, 56(%rdi)

    movq $0, %rax
    ret
