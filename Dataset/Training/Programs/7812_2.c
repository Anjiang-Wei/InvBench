/*
Fibonacci Sequence Algorithm with Verification
Computes the nth Fibonacci number using iterative logic.
Verify that each computed Fibonacci number meets the expected property.
*/

extern void abort(void);
#include <assert.h>

void reach_error() { assert(0); }

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

extern int __VERIFIER_nondet_int(void);

int main() {
    int n;

    // Non-deterministic input for the position in Fibonacci sequence
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n < 20); // Limit taken for demonstration purposes

    // Variables to hold current and previous Fibonacci numbers
    int prev = 0, curr = 1, next;
    int count = 1;

    // Handling initial condition for Fibonacci sequence
    if (n == 0) {
        curr = 0;
    }

    while (count < n) {
        next = prev + curr;
        prev = curr;
        curr = next;
        count++;

        // Verification rule at each step: Fib(i+1) = Fib(i) + Fib(i-1)
    }

    // Final assertion: The calculated Fibonacci number must be positive
    __VERIFIER_assert(curr >= 0);

    return 0;
}