// New C program for automated verification tools

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprog.c", 6, "reach_error"); }
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
    // Fibonacci sequence-like computation
    long long a, b, n;
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0);

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 2);

    long long fib_curr = b;
    long long fib_prev = a;
    long long fib_temp;

    int i = 2;

    while (i < n) {
        fib_temp = fib_curr;
        fib_curr = fib_prev + fib_curr;
        fib_prev = fib_temp;

        i++;
    }

    // Verification condition: nth Fibonacci number should be non-negative
    __VERIFIER_assert(fib_curr >= 0);

    printf("The %lld-th value in the derived Fibonacci-like sequence is %lld\n", n, fib_curr);

    return 0;
}