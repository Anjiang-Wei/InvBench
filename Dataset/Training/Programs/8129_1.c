#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 5, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);

    long long a = 0, b = 1, fib = 0;
    int i;

    // Compute the Fibonacci sequence up to n
    for (i = 0; i < n; ++i) {
        if (i == 0) {
            fib = a;
        } else if (i == 1) {
            fib = b;
        } else {
            fib = a + b;
            a = b;
            b = fib;
        }
    }

    // Verify if the computed Fibonacci number is non-negative
    __VERIFIER_assert(fib >= 0);

    printf("Fibonacci(%d) = %lld\n", n, fib);
    return 0;
}