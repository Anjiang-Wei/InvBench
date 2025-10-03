#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "my_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(void) {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 12); // To avoid integer overflow

    int sum = 0;
    int i;

    for (i = 0; i <= N; i++) {
        sum += factorial(i);
    }

    // Here's a fictitious condition to verify:
    __VERIFIER_assert(sum >= 0);

    printf("The sum of factorials up to %d is %d\n", N, sum);

    return 0;
}