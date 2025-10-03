/*
  Fibonacci Sequence Verification
  This program computes the Fibonacci sequence
  and checks certain properties about its elements.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 10, "reach_error"); }
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
    int n, i;
    long long *fib;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 1 && n <= 50);

    fib = malloc(sizeof(long long) * (n + 1));

    fib[0] = 0;
    fib[1] = 1;

    for (i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        // Verify that Fibonacci numbers grow monotonically
        __VERIFIER_assert(fib[i] >= fib[i - 1]);
    }

    // Check some known Fibonacci properties

    return 0;
}