#include <assert.h>
#include <stdlib.h>

// External function stubs to simulate nondeterministic inputs
extern int __VERIFIER_nondet_int();
extern void abort(void);
void reach_error() { assert(0); }

// To model the behavior of verifying conditions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    n = __VERIFIER_nondet_int(); // Non-deterministically choose n
    if (n < 0) {
        // For the purposes of verification, assume n is non-negative
        return 0;
    }

    int fib_n = 0;
    int counter = 0;
    while (counter < 15) { // Limiting to avoid excessive computation
        fib_n = fibonacci(counter);
        __VERIFIER_assert(fib_n >= 0); // Ensure that Fibonacci numbers are non-negative
        counter++;
    }

    return 0;
}