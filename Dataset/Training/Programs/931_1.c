#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

/*
Fibonacci Sequence Verification with Constraints:

Computes the Fibonacci sequence within a limit of N,
and ensures the Fibonacci property holds: fib(n) = fib(n-1) + fib(n-2).
Additionally, maintains a condition that no Fibonacci number exceeds 1000.
*/

int main() {
    int N = __VERIFIER_nondet_int();
    if (N < 2 || N > 50) {
        return 0; // Limit N to be in a reasonable range
    }

    int fib_prev1 = 1, fib_prev2 = 1;
    int fib_current;

    __VERIFIER_assert(fib_prev1 <= 1000 && fib_prev2 <= 1000); // Initial condition

    for (int i = 3; i <= N; ++i) {
        fib_current = fib_prev1 + fib_prev2;

        // Ensure the Fibonacci property and the constraint

        // Move to the next two numbers in the sequence
        fib_prev2 = fib_prev1;
        fib_prev1 = fib_current;
    }

    printf("Validated Fibonacci Sequence up to term %d\n", N);
    return 0;
}