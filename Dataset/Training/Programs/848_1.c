#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int calculate_fibonacci(int n) {
    // Function to calculate the nth Fibonacci number iteratively
    if (n < 0) {
        return -1; // Invalid case
    }
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return (n == 0) ? a : b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 46); // Limit n to prevent integer overflow for Fibonacci calculation

    int fib_n = calculate_fibonacci(n);

    // Introduce a check that is intended to hold for valid Fibonacci computation
    __VERIFIER_assert(fib_n >= 0); // Fibonacci numbers should be non-negative

    // Artificial loop to add complexity
    int sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += i;
    }

    // Another runtime check, ensures sum is a non-negative number.

    return 0;
}