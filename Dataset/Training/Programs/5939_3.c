#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci Sequence Calculation
computes n-th Fibonacci number using iteration
*/

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 50);

    // Base cases
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Fibonacci computation
    int a = 0, b = 1, fib = 0;

    int i = 2;
    while (i <= n) {
        fib = a + b;
        a = b;
        b = fib;
        i = i + 1;
    }

    // Verify that the fib value is a valid Fibonacci number for some constraints
    __VERIFIER_assert(fib >= 0);

    return fib;
}