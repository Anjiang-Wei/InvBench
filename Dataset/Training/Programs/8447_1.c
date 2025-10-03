#include <stdio.h>
#include <stdlib.h>

/*
Fibonacci Sequence with even-odd value accumulation
computes Fibonacci sequence up to n, accumulates values based on even or odd
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
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
    int n, a = 0, b = 1, fib, even_sum = 0, odd_sum = 0;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 1000); // Ensure n is within a reasonable range

    for (int i = 0; i < n; i++) {
        if (n == 1) {
            fib = a;
        } else if (n == 2) {
            fib = b;
        } else {
            fib = a + b;
            a = b;
            b = fib;
        }

        if (fib % 2 == 0) {
            even_sum += fib;
        } else {
            odd_sum += fib;
        }
    }

    // Verify that the sum of even and odd Fibonacci numbers is non-negative, which should always be true
    __VERIFIER_assert(even_sum >= 0 && odd_sum >= 0);
    printf("Sum of even Fibonacci: %d\n", even_sum);
    printf("Sum of odd Fibonacci: %d\n", odd_sum);
    return 0;
}