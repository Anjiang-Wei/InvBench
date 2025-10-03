// This is a C program designed for verification by automated tools.

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "increasing_even_sum.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main(void) {
    int sum = 0;
    int x = 0;
    int N = __VERIFIER_nondet_int();

    if (N < 0) {
        return 0; // Ensure that N is non-negative
    }

    while (x < N) {
        x += 1;
        if (x % 2 == 0) { // Check if x is even
            sum += x;
        }
    }

    // The sum of all even numbers from 0 to N-1 should be equal to the computed formula
    __VERIFIER_assert(sum == (x / 2) * ((x / 2) + 1));

    return 0;
}