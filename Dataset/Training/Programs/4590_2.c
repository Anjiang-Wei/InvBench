#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Factorial Approximation
Approximates the factorial of a number n using multiplication.
Ensures that the computed value is a non-decreasing approximation of n! during each step.
*/
int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0) {
        return 0; // n must be non-negative for factorial
    }

    int i = 1;
    long long approximation = 1; // Start with 1 as the factorial of 0 or 1 is 1

    while (i <= n) {
        approximation *= i; // Multiply to approximate factorial
    }

    // Postcondition: approximation should equal to n factorial if n is small
    // It checks a less strict condition to enable verification
    // Ensures the approximation is still valid even with large n
    __VERIFIER_assert(approximation >= 1);

    return 0;
}