// New C Program Example

#include <assert.h>
#include <stdbool.h>

extern void abort(void);
void reach_error() { assert(0); }
extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    unsigned int a = __VERIFIER_nondet_uint();
    unsigned int b = __VERIFIER_nondet_uint();

    // Assume reasonable bounds to prevent excessive computation in analysis
    if (a > 500 || b > 500) {
        return 0;
    }

    unsigned int sum_a = 0;
    unsigned int sum_b = 0;

    // Loop to perform incremental summation
    while (a > 0) {
        sum_a += a;
        a--;
    }

    while (b > 0) {
        sum_b += b;
        b--;
    }

    // Create a condition that must be true for verification
    if (sum_a != sum_b) {
        if (sum_a > sum_b) {
            __VERIFIER_assert(sum_a - sum_b > 0);
        } else {
        }
    } else {
    }

    return 0;
}