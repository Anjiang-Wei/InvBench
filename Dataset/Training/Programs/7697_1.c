#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

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

// Function to compute the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Example function to demonstrate verification
void compute_fibonacci_and_assert(int k) {
    int fib_k;
    int sum = 0;

    // Pre-condition assumptions
    assume_abort_if_not(k >= 5 && k <= 15);

    // Compute Fibonacci and maintain sum of numbers
    for (int i = 0; i <= k; i++) {
        fib_k = fibonacci(i);
        sum += fib_k;
        __VERIFIER_assert(fib_k >= 0); // Fibonacci numbers are non-negative
    }

    // Post-condition: Check if the sum is greater than k
    __VERIFIER_assert(sum > k);
}

int main() {
    int k = __VERIFIER_nondet_int();
    compute_fibonacci_and_assert(k);
    return 0;
}