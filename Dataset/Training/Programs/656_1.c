// A C program that implements a simple number sequence verification task

#include <stdio.h> // For printf (to provide a testable output)
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "sequence_verification.c", 4, "reach_error"); }

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
    return;
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int a = 0, b = 1, t;
    for (int i = 2; i <= n; ++i) {
        t = a + b;
        a = b;
        b = t;
    }
    return b;
}

int main(void) {
    // Generate a non-deterministic sequence length
    int n = __VERIFIER_nondet_int();

    // Assume a reasonable bound on n for computational purposes
    assume_abort_if_not(n > 0 && n < 20);

    // Generate the sequence and validate it
    for (int i = 0; i < n; ++i) {
        int fib_i = fibonacci(i);
        printf("Fibonacci(%d) = %d\n", i, fib_i);
        // Assert a basic property of Fibonacci numbers, like non-negativity
        __VERIFIER_assert(fib_i >= 0);
    }

    return 0;
}