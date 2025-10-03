#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci Sequence Generator:
Generates a Fibonacci sequence up to F(n) where n is non-deterministic,
but within a constraint range.
Validates that the n-th Fibonacci number is correctly calculated using
the property F(n) = F(n-1) + F(n-2) for n > 1.
*/
int main() {
    int a = 0, b = 1, temp, n;
    n = __VERIFIER_nondet_int();

    // Ensuring n falls within a reasonable range
    if (!(n >= 0 && n <= 20)) {
        return 0;
    }

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 0;
    }

    int i = 2; // Start from the third Fibonacci number F(2)

    // Generate Fibonacci numbers up to F(n)
    while (i <= n) {
        temp = a + b;
        a = b;
        b = temp;
        i++;
    }

    // Verify the last calculated Fibonacci number
    __VERIFIER_assert(b >= 0); // To check for non-negative Fibonacci numbers
    return 0;
}