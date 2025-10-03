/*
Fibonacci Sequence with Constraints
computes n-th Fibonacci number if n is less than or equal to 20
verifies property: fib(n) <= 6765
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 5, "reach_error"); }

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
    unsigned int n;
    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n <= 20); // constraint condition

    unsigned int fib_prev = 0;
    unsigned int fib_curr = 1;
    unsigned int fib_next = 0;
    unsigned int i = 2;

    if (n == 0) {
        fib_next = 0;
    } else if (n == 1) {
        fib_next = 1;
    } else {
        while (i <= n) {
            fib_next = fib_prev + fib_curr;
            fib_prev = fib_curr;
            fib_curr = fib_next;
            i++;
        }
    }

    // Verify the property: Fibonacci number should be less than or equal to 6765 for n <= 20
    __VERIFIER_assert(fib_next <= 6765);

    printf("Fibonacci number for n=%u is %u\n", n, fib_next);
    return 0;
}