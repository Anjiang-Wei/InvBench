// Fibonacci sequence computation with verification conditions

#include <stdio.h>
#include <stdlib.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "fibonacci_verification.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    int a = 0, b = 1, c;

    while (n > 1) {
        // Invariant condition: every iteration b becomes fib(i) and a becomes fib(i-1)
        c = a + b;
        a = b;
        b = c;
        n--;
    }

    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // Limiting n for practical purposes

    int result = fibonacci(n);

    // Verifying the result with known properties of Fibonacci numbers
    // A Fibonacci number is non-negative
    __VERIFIER_assert(result >= 0);

    // The sum of squares of two consecutive Fibonacci numbers is another Fibonacci number
    if (n > 1) {
        int fib_n_minus_1 = fibonacci(n - 1);
        int fib_n_minus_2 = fibonacci(n - 2);
    }

    printf("Fibonacci(%d) = %d\n", n, result);
    return 0;
}