/*
  Newton's method for approximating square roots
  The program approximates the square root of a non-negative integer n.
  It verifies the convergence of the algorithm.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newton-approx.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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

long long absolute(long long a) {
    return a < 0 ? -a : a;
}

int main() {
    int n;
    long long x, prev_x, diff;

    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0 && n <= 1000);

    x = n / 2;  // Initial guess
    prev_x = 0; // Previous guess
    diff = 1;   // Difference between guesses

    while (diff > 1) {
        __VERIFIER_assert(x * x - n <= 2 * x * diff && x * x - n >= -2 * x * diff);

        if (prev_x == x) {
            break; // Termination condition based on saturation
        }

        prev_x = x;
        x = (x + n / x) / 2;
        diff = absolute(prev_x - x);
    }

    printf("Approximate square root of %d is %lld\n", n, x);

    return 0;
}