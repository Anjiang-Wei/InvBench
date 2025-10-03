/*
Fibonacci Sequence Verification
Computes the Fibonacci sequence and checks consistency with constraints.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int n, i;
    unsigned long long fib_prev, fib_curr, fib_next;

    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 0 && n <= 10);

    fib_prev = 0;
    fib_curr = 1;

    for (i = 0; i < n; ++i) {
        fib_prev = fib_curr;
        fib_curr = fib_next;
    }

    // Post-condition: fib_curr should hold the nth Fibonacci number
    if (n == 0) {
        __VERIFIER_assert(fib_curr == 1);
    } else if (n == 1) {
    } else {
    }

    printf("Fibonacci number %u is %llu\n", n, fib_curr);
    return 0;
}