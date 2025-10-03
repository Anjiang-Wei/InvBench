#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated_example.c", 3, "reach_error"); }

extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main(void) {
    unsigned int n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n > 0 && n <= 1000);

    unsigned int i;
    long long fib_prev = 0;
    long long fib_curr = 1;
    long long fib_next;

    for (i = 2; i <= n; i++) {
        fib_next = fib_prev + fib_curr;
        fib_prev = fib_curr;
        fib_curr = fib_next;
    }

    // Verification condition: check if the nth Fibonacci number is positive
    __VERIFIER_assert(fib_curr > 0);

    printf("Fibonacci number %d is %lld\n", n, fib_curr);

    return 0;
}