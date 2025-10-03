#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c, i;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int fib_value;

    if (n >= 0) {
        fib_value = fibonacci(n);
    } else {
        fib_value = -1; // Invalid input for Fibonacci
    }

    if (n >= 0 && n <= 10) {
        __VERIFIER_assert(fib_value <= 55); // Fibonacci(10) = 55 is the maximum for n <= 10
    }

    return 0;
}