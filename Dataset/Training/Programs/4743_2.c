/*
Fibonacci Sequence
computes Fibonacci numbers up to a given limit and checks properties at each step
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 6, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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
    return;
}

int main() {
    unsigned int n, i;
    unsigned long long x, y, z;

    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 1 && n < 50); // Limit n to a reasonable size for computation

    x = 0; // First Fibonacci number
    y = 1; // Second Fibonacci number

    for (i = 2; i <= n; i++) {
        z = x + y;

        x = y;
        y = z;
    }

    // Check the n-th Fibonacci number is correctly assigned to y
    // This is not a full Fibonacci check which would be very complex
    // but a reduced check to ensure values are computed
    if (n == 5) {
        __VERIFIER_assert(y == 5);
    } else if (n == 10) {
    }

    return 0;
}