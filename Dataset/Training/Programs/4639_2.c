#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

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
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    int factorial = 1;
    int i = 1;

    while (i <= n) {
        factorial *= i;
        i++;
    }

    if (n > 1) {
    } else {
        __VERIFIER_assert(factorial == 1);
    }

    printf("Factorial of %d is %d\n", n, factorial);

    return 0;
}