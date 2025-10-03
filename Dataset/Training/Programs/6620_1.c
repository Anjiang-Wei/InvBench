#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "example_program.c", 5, "reach_error");
}

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

extern int __VERIFIER_nondet_int(void);

int main(void) {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 100);
    int sum = 0, i = 1;

    // Loop to calculate the sum of squares up to n
    while (i <= n) {
        sum += i * i;
        i++;
    }
    // Check that the calculated sum is non-negative
    __VERIFIER_assert(sum >= 0);

    // Print the result for reference
    printf("Sum of squares up to %d is %d\n", n, sum);

    return 0;
}