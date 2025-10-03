#include <limits.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

int main() {
    int i, N;
    long long product = 1;

    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 20); // Constrain N to a small range to avoid overflow risk

    for (i = 1; i <= N; i++) {
        product *= i;                     // Calculating factorial
        assume_abort_if_not(product > 0); // Prevent overflow
    }

    // The computed factorial for small values of N should be greater than 0
    __VERIFIER_assert(product > 0);

    return 0;
}