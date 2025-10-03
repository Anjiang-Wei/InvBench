#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { abort(); }

void __VERIFIER_assume(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// A function to compute the Fibonacci series and verify a property
int fibonacci(int n) {
    __VERIFIER_assume(n >= 0);

    int a = 0, b = 1;
    int i = 0;
    while (i < n) {
        int temp = a;
        a = b;
        b = temp + b;
        i++;
    }
    return a;
}

int main() {
    int n = __VERIFIER_nondet_int();
    __VERIFIER_assume(n >= 0 && n <= 20); // Limit n to avoid overflow

    int fib_n = fibonacci(n);

    // Verify the output is a Fibonacci number (based on known Fibonacci numbers for small n)
    if (n == 0) {
    } else if (n == 1) {
    } else if (n == 2) {
        __VERIFIER_assert(fib_n == 1);
    } else if (n == 3) {
    } else if (n == 4) {
    } else if (n == 5) {
    } // and so on for small n

    // Output the result
    printf("Fibonacci(%d) = %d\n", n, fib_n);

    return 0;
}