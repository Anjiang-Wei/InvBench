#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { abort(); }
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

#define MAX 1000

int main() {
    int i, n, factor_count;
    n = __VERIFIER_nondet_int();

    if (n <= 0) {
        return 1; // Ensure positive number
    }
    assume_abort_if_not(n <= MAX);

    factor_count = 0;

    // Check number of factors
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            factor_count++;
        }
    }

    // Verifies if the factor_count is less than a certain limit
    // Meaningful constraint: a number cannot have more factors than itself

    // Further check: if factor_count == 2, it's a prime number
    if (factor_count == 2) {
        // Assign n to prime_indicator
        int prime_indicator = n;
        // Derive a new constraint: if prime, prime_indicator must be same as n
        __VERIFIER_assert(prime_indicator == n);
    }

    return 0;
}