#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void); // External nondeterministic input function

void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    int a = 0;
    int b = 1;
    int i = 0;
    int fib = 0;

    // Computes Fibonacci numbers until the index reaches 2*n
    while (i < 2 * n) {
        fib = a + b;
        a = b;
        b = fib;
        i++;

        // Check that Fibonacci numbers don't overflow int
        __VERIFIER_assert(fib >= a); // Simple overflow check
    }

    assume_abort_if_not(i == 2 * n);
    printf("Fibonacci number at index %d (2*n) is: %d\n", 2 * n, fib);

    return 0;
}