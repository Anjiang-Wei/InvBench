#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int i, n, factorial;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Restrict the value of n for analysis

    factorial = 1;
    i = 1;

    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verify that the computed factorial is greater than zero
    __VERIFIER_assert(factorial > 0);

    printf("Factorial of %d is %d\n", n, factorial);

    return 0;
}