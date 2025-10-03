#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }
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
}

extern int __VERIFIER_nondet_int(void);

#define MAX_ITER 50

int main() {
    int n, i;
    long long factorial = 1;

    n = __VERIFIER_nondet_int();

    // Assume n is a positive integer less than 20 to prevent overflow
    assume_abort_if_not(n > 0 && n < 20);

    for (i = 1; i <= n && i < MAX_ITER; i++) {
        factorial *= i;
        // Check for potential overflow
        assume_abort_if_not(factorial > 0);
    }

    printf("Factorial of %d is %lld\n", n, factorial);

    // Verification condition: Factorial of n is correctly computed
    if (n == 3) {
    } else if (n == 4) {
        __VERIFIER_assert(factorial == 24);
    }

    return 0;
}