#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int n, sum, i, fib1, fib2, fib;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 1000);

    sum = 0;
    fib1 = 0;
    fib2 = 1;

    for (i = 0; i < n; i++) {
        if (i <= 1) {
            fib = i;
        } else {
            fib = fib1 + fib2;
            fib1 = fib2;
            fib2 = fib;
        }

        if (fib % 2 == 0) {
            sum += fib;
        }
    }

    // Verification check: the sum of even Fibonacci numbers should always be non-negative
    __VERIFIER_assert(sum >= 0);

    printf("The sum of even Fibonacci numbers up to term %d is %d\n", n, sum);
    return 0;
}