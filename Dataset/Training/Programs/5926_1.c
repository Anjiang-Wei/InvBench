#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci Sequence:
Calculates Fibonacci numbers in a loop.
Ensures the values do not exceed a certain threshold.
*/

int main() {
    int n, threshold;
    int prev1 = 0, prev2 = 1;
    int current, i;

    n = __VERIFIER_nondet_int();
    threshold = __VERIFIER_nondet_int();

    if (!(n >= 0 && threshold > 0 && threshold <= 1000)) {
        return 0;
    }

    if (n == 0) {
        current = prev1;
    } else if (n == 1) {
        current = prev2;
    } else {
        for (i = 2; i <= n; i++) {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
            if (current > threshold) {
                current = threshold; // Cap the Fibonacci calculation to the threshold
                break;
            }
        }
    }

    __VERIFIER_assert(current <= threshold);
    return 0;
}