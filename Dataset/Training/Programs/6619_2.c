#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error() {
    printf("Error reached!\n");
    exit(1);
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int __VERIFIER_nondet_int() {
    return rand() % 100; // returns a random number between 0 and 99 for simplicity
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    int n, i, fib, sum_even, sum_odd;
    n = __VERIFIER_nondet_int() % 20; // Limiting n to ensure termination

    sum_even = 0;
    sum_odd = 0;

    for (i = 0; i < n; i++) {
        fib = fibonacci(i);

        if (fib % 2 == 0) {
            sum_even += fib;
        } else {
            sum_odd += fib;
        }
    }

    printf("Sum of even Fibonacci numbers: %d\n", sum_even);
    printf("Sum of odd Fibonacci numbers: %d\n", sum_odd);

    // Check some properties of Fibonacci numbers
    __VERIFIER_assert(sum_odd >= 0);

    return 0;
}