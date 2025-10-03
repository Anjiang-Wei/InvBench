// Simple C program with a loop and condition check
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a, b, c, i;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 1000);
    assume_abort_if_not(b >= 0 && b <= 1000);

    c = 0;
    i = 0;

    while (i < 10) {
        c = a * b + c;
        // Ensure the computed result `c` remains within certain limits
        a = a + 1;
        b = b + 2;
        i++;
    }

    // Final check to ensure the computation was as expected
    __VERIFIER_assert(c >= a * b);
    printf("Final values: a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}