#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int fib(int n) {
    if (n <= 1) {
        return n;
    }

    int a = 0, b = 1, c, i;
    for (i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // Limit the range for verification purposes
    int result = fib(n);

    // A constraint: result should be non-negative
    __VERIFIER_assert(result >= 0);

    // Another constraint: result should not exceed 6765 for n in the range 0 to 20

    printf("Fibonacci of %d is %d\n", n, result);
    return 0;
}