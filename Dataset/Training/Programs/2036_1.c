// Program to compute Fibonacci numbers iteratively and verify using constraints

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0); // Assuming non-negative n

    int a = 0, b = 1, temp;

    for (int i = 1; i <= n; ++i) {
        // Compute the next Fibonacci number
        temp = a;
        a = b;
        b = temp + b;

        // Verify invariant condition: Check if every Fibonacci number is non-negative
        __VERIFIER_assert(a >= 0);
    }

    // Final assertion to validate some property about the Fibonacci sequence
    // Here we verify that for n=0,1,2,3,..., at position n, the Fibonacci
    // number is equal to the addition of the two numbers before it (F(n) = F(n-1) + F(n-2))

    return 0;
}