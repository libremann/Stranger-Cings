#include <stdio.h>
#include "jmp.h"

jmp_buf jump_buffer;

int main () {
    int a=setjmp(jump_buffer);
    if(a==0) {
        printf("Hello World!\n");
        longjmp(jump_buffer, 10);
    } else if(a==10) {
        printf("Good Bye :)\n");
    }
}
