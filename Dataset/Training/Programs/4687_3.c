#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci Sequence Program
Compute Fibonacci sequence up to a certain non-deterministic limit n
Ensure that the sequence is correctly generated.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 50) {
        return 0; // Limit range to prevent excessive computation
    }

    long long fib1 = 0;
    long long fib2 = 1;
    long long current_fib = 0;
    int count = 2;

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 0;
    }

    while (count <= n) {
        current_fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = current_fib;
        count++;
    }

    // Check the n-th Fibonacci number, basic constraint check
    __VERIFIER_assert(current_fib >= 0);

    return 0;
}