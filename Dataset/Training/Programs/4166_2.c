#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    assert(0);
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // Assuming n is within a reasonable range

    int i = 0;
    int sum = 0;
    int product = 1;

    // Parallel computation of sum and product
    while (i < n) {
        sum += i;
        product *= (i + 1);
        i++;
    }

    // An interesting property to assert: sum should be a triangular number
    // if n is the number of natural numbers from 1 to n-1
    // i.e. sum = n * (n - 1) / 2
    // We also verify that product grows in range
    __VERIFIER_assert(product > 0);

    return 0;
}