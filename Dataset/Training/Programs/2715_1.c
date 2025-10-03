#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }
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

// Extended Fibonacci-style sequence based on two initial numbers
int main() {
    int a, b, limit, f1, f2, sum;

    // Non-deterministically choose initial values within a reasonable range
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 10);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 10);

    // The limit for the loop
    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0 && limit <= 10);

    f1 = a;
    f2 = b;
    sum = 0;

    // A loop that continues aggregating values in a sequence style
    for (int i = 0; i < limit; i++) {
        int fn = f1 + f2;
        f1 = f2;
        f2 = fn;

        // Only add terms which are even to 'sum'
        if ((fn % 2) == 0) {
            sum += fn;
        }
    }

    // Ensure the sum is non-negative
    __VERIFIER_assert(sum >= 0);

    printf("The computed sum of the sequence is: %d\n", sum);

    return 0;
}