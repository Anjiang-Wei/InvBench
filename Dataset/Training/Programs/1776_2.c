#include <stdio.h>
#include <stdlib.h>

/* Function prototypes for reach_error and other required externals */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 9, "reach_error"); }
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

/* Main computation logic */
int main() {
    int n, i;
    int sum1 = 0, sum2 = 0;
    n = __VERIFIER_nondet_int();

    if (n < 1 || n > 1000) {
        return 0;
    }

    for (i = 1; i <= n; i++) {
        sum1 += i;
        sum2 += i * i;
    }

    // Check that the computed sums satisfy specific properties
    __VERIFIER_assert(sum2 >= sum1);

    printf("Sum of first n natural numbers: %d\n", sum1);
    printf("Sum of squares of first n natural numbers: %d\n", sum2);

    return 0;
}