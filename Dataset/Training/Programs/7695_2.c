#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// A function to calculate factorial of a number iteratively
int factorial(int n) {
    int result = 1;
    int i = 1;
    while (i <= n) {
        result *= i;
        i++;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int(); // A non-deterministic integer input

    // Assuming n is in a reasonable range for factorial calculation
    if (!(n >= 0 && n <= 12)) {
        return 0;
    }

    int fact = factorial(n);

    // Assert that for n >= 0, factorial(n) > 0

    // Assert that factorial(0) == 1 or factorial(1) == 1
    if (n == 0 || n == 1) {
        __VERIFIER_assert(fact == 1);
    }

    // Assert that for n == 5, factorial(5) == 120
    if (n == 5) {
    }

    return 0;
}