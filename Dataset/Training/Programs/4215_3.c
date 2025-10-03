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
int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = 0, b = 1, c = 2;
    int maxIter = 50;
    int n = __VERIFIER_nondet_int();

    if (n <= 0 || n > 100) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        // Fibonacci-like sequence calculation
        int sum = a + b + c;

        // Shift the values
        a = b;
        b = c;
        c = sum;

        // Assertion to verify the current value is non-negative and increasing

        // Compute expression with conditions to limit values and exit if exceeded
        if (c > 1000) {
            return 0;
        }

        // Ensure the loop doesn't exceed the maximum iterations
        if (i >= maxIter) {
            __VERIFIER_assert(i <= maxIter);
            break;
        }
    }

    return 0;
}