#include <assert.h>
extern int __VERIFIER_nondet_int(void);

void reach_error() { assert(0); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0); // n should be positive

    int sum = 0;     // Accumulate sum of numbers
    int product = 1; // Accumulate product of numbers
    int i;

    for (i = 1; i <= n; i++) {
        sum += i;
        product *= i;

        // Condition to check progression of summation and product accumulation
        __VERIFIER_assert(sum >= i);
    }

    // Check the final results (known characteristics):

    return 0;
}