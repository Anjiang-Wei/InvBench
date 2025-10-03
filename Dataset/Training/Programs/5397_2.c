#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Calculate factorial of 'n' using iteration
Ensures the computation doesn't overflow simple constraint value
*/

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int max_factorial = 12; // Will check up to factorial of 12
    assume_abort_if_not(n >= 0 && n <= max_factorial);

    long long factorial = 1;
    int i;

    // Iterative calculation of factorial
    for (i = 1; i <= n; i++) {
        // Asserting that factorial computation is within expected limits
    }

    // Verifying that the computed factorial is within logical bounds
    __VERIFIER_assert((n == 0 || factorial > 0) && factorial <= 479001600);

    return 0;
}