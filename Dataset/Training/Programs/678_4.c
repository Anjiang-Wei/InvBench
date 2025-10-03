/*
  Fibonacci Sequence Verification
  Computes Fibonacci sequence values and verify certain properties
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int n;
    unsigned long long a, b, temp;
    unsigned long long sum;
    unsigned int counter = 0;

    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n < 100); // Assume n is suitably small for handling

    a = 0;
    b = 1;
    sum = 0;

    while (counter < n) {
        a = b;
        b = temp + b;

        // Check for overflow condition in Fibonacci

        sum += a;
    }

    // Final validation: nth Fibonacci number as sum of the two previous
    if (n > 1) {
        __VERIFIER_assert(b == a + (a - b + temp)); // This checks 'b = a + (a - prev)'
    }

    printf("Fibonacci sequence up to term %u calculated.\n", n);
    return 0;
}