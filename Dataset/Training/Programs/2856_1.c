#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, i, prod;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Bounded non-determinism for easier verification

    prod = 1;

    for (i = 1; i <= n; i++) {
        prod *= i; // Factorial computation: prod = n!

        if (prod < 0) {
            break; // Overflow check
        }
    }

    if (n <= 5) {
        // since n! <= 120 for n <= 5, prod should not overflow
        __VERIFIER_assert(prod > 0);
    } else {
        // for n > 5, the factorial might be too large for a standard int
    }

    return 0;
}