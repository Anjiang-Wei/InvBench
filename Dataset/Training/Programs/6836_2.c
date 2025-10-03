/*
Fibonacci Sequence and Verification
This program calculates Fibonacci numbers iteratively and verifies properties of the sequence.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "fibonacci.c", 10, "reach_error"); }

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
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 47); // Limit N to prevent integer overflow

    long long fib_N;
    if (N == 0) {
        fib_N = 0;
    } else if (N == 1) {
        fib_N = 1;
    } else {
        long long a = 0;
        long long b = 1;
        int i = 2;

        while (1) {
            if (!(i <= N)) {
                break;
            }

            fib_N = a + b;
            a = b;
            b = fib_N;
            i = i + 1;

            // Check Fibonacci property: Fib(n) = Fib(n-1) + Fib(n-2),
            // although trivial, serves the pattern.
        }
    }

    // Verification: Fibonacci numbers should never be negative
    __VERIFIER_assert(fib_N >= 0);

    printf("Fib(%d) = %lld\n", N, fib_N);
    return 0;
}