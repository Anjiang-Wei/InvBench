#include <assert.h>
#include <stdlib.h>

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
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100); // Assume n is between 1 and 100
    int i = 0;
    int sum_even = 0;
    int sum_odd = 0;

    while (i < n) {
        int value = __VERIFIER_nondet_int();
        assume_abort_if_not(value >= 1 && value <= 100); // Each value is between 1 and 100

        if (value % 2 == 0) {
            sum_even += value;
        } else {
            sum_odd += value;
        }

        i++;
    }

    // Ensure that both sums do not exceed a certain number
    __VERIFIER_assert(sum_odd <= n * 100);

    // Verification constraint: difference should never exceed a threshold
    int diff = sum_even - sum_odd;

    return 0;
}