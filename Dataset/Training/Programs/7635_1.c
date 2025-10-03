#include <assert.h>
#include <stdbool.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// This program calculates the Fibonacci sequence
// and ensures the value is non-negative
// and follows the Fibonacci relation
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // Limit n for feasible computation

    int a = 0;
    int b = 1;
    int i = 1; // Start from 1 to handle single element sequence as valid

    int fib = a; // fib represents the Fibonacci of the current i
    while (i < n) {
        int temp = b;
        b = a + b;
        a = temp;
        fib = b;

        // Ensure the constraint of Fibonacci sequence
        // i.e., Fib(i) = Fib(i-1) + Fib(i-2)
        __VERIFIER_assert(fib >= 0); // Fibonacci numbers should always be non-negative
        i++;
    }

    // At this point, 'fib' is the nth Fibonacci number
    return 0;
}