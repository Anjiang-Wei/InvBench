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
    ERROR : { reach_error(); }
    }
    return;
}

int counter = 0;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n, fib_result, sum, i;

    // Get a nondeterministic input value
    n = __VERIFIER_nondet_int();
    // Assume n is within a reasonable range for demonstration
    assume_abort_if_not(n >= 0 && n <= 20);

    sum = 0;

    // Iteratively calculate the sum of first n Fibonacci numbers
    for (i = 0; i <= n; i++) {
        fib_result = fibonacci(i);
        sum += fib_result;
        __VERIFIER_assert(sum >= 0); // Simple property check to ensure non-negativity
    }

    // Another property check after the loop
    __VERIFIER_assert(sum > 0 || n == 0); // Ensure sum is greater than 0 unless n is 0

    printf("Sum of first %d Fibonacci numbers is: %d\n", n, sum);
    return 0;
}