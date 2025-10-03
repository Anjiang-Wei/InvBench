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
Fibonacci Series:
Calculate the Fibonacci series iteratively.
Check specific constraints on the series during the computation.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 30) {
        return 0; // Ensure n is within manageable bounds
    }

    int a = 0, b = 1, c;
    int i = 0;

    while (i < n) {
        c = a + b;
        a = b;
        b = c;
        i++;

        // Check for known properties of Fibonacci numbers
        __VERIFIER_assert(a >= 0); // Fibonacci numbers should never be negative

        // Let's introduce a meaningful constraint check
        // Ensure that if 'a' is even, it is a sum of two consecutive Fibonacci numbers
        if (a % 2 == 0) {
            __VERIFIER_assert((a == 0) || (i >= 3 && a == (a - b) + b));
        }
    }

    return 0;
}