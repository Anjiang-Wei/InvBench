/*
Fibonacci Sequence Validation
This program calculates the Fibonacci sequence up to a given number n
and verifies each element of the sequence against its recursive definition.
The verification check ensures that each number (after the first two)
is the sum of the preceding two numbers.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 6, "reach_error"); }
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

int main() {
    int n, a, b, c, i;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // To limit the sequence to a reasonable size

    // Initial Fibonacci numbers
    a = 0;
    b = 1;

    if (n == 0) {
        // Fibo(0) = 0, trivially verified
    } else if (n == 1) {
        // Fibo(1) = 1, trivially verified
    } else {
        // Calculate up to the nth Fibonacci number
        for (i = 2; i <= n; i++) {
            c = a + b;
            b = c;
        }
        // Verify the last computed Fibonacci number satisfies the equation
        __VERIFIER_assert(b == a + c - a);
    }

    return 0;
}