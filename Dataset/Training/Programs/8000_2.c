#include <assert.h>
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

// Function to compute the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 12) {
        return 0; // restrict n to a safe range for factorial calculation
    }

    int result = factorial(n);

    // Verify the result for n! is non-negative and less than 13! (to prevent overflow)
    __VERIFIER_assert(result <= 479001600);

    return 0;
}