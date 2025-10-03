#include <assert.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int(); // number of terms
    int a = 1, b = 1;                // starting values of Fibonacci sequence
    int fib;                         // holds the current Fibonacci number
    int i = 0;                       // loop counter

    // Precondition: n should be a non-negative integer
    if (!(n >= 0)) {
        return 0;
    }

    while (i < n) {
        // Calculate the next Fibonacci number
        fib = a + b;
        a = b;
        b = fib;

        i++;
    }

    // Postcondition: For n>=2, the i-th Fibonacci number should be non-negative (as in Fibonacci sequence)
    if (n >= 2) {
        __VERIFIER_assert(fib >= 0);
    }

    return 0;
}