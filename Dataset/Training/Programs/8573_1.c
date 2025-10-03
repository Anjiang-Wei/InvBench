#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_program.c", 7, "reach_error"); }

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

int main(void) {
    int a, b, sum, n, i;

    a = 1;       // initial value
    b = 1;       // initial value
    sum = a + b; // initial sum

    // Assume n is assigned a positive integer less than or equal to 10
    n = 5;

    // A loop that processes n numbers in the sequence
    for (i = 0; i < n; i++) {
        a = a + b;
        b = b + a;
        sum = sum + a + b;

        // Constraint to ensure properties of the sequence
        assume_abort_if_not(a > 0 && b > 0); // Assume terms are positive
    }

    // Validate the sum through assertion (property holds if this passes)
    __VERIFIER_assert(sum > 0);

    printf("Final sum of the sequence: %d\n", sum);
    return 0;
}