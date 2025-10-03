#include <assert.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// The program calculates the factorial of a number n.
int main() {
    int n = __VERIFIER_nondet_int();
    int factorial = 1;
    int i = 1;

    assume_abort_if_not(n >= 0); // Assume n is non-negative

    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Check if the factorial calculation matches the actual factorial value in a small range
    if (n < 6) {
        int expected[] = {1, 1, 2, 6, 24, 120}; // precomputed factorial values for n = 0 to 5
        __VERIFIER_assert(factorial == expected[n]);
    }

    return 0;
}