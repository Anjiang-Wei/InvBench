#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function to calculate the Fibonacci number iteratively
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    int a = 0, b = 1;
    int fib;

    while (n > 1) {
        fib = a + b;
        a = b;
        b = fib;
        n = n - 1;
    }

    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // To ensure computational feasibility

    int result = fibonacci(n);

    // Verify some basic properties of the Fibonacci sequence
    if (n == 0) {
    }
    if (n == 1) {
        __VERIFIER_assert(result == 1);
    }

    printf("Fibonacci of %d is %d\n", n, result);

    return 0;
}