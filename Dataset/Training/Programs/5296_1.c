#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int sum = 0;

    if (n <= 0) {
        return 0; // Ensure n is positive
    }

    if (x < 0 || y < 0) {
        return 0; // Ensure x and y are non-negative
    }

    // Execute a simple loop that will sum numbers in a range
    for (int i = 0; i < n; i++) {
        sum += x;
        if (sum > y) {
            // Reset sum when it exceeds y, representing a bounded computation
            sum = 0;
        }
    }

    // After the loop, we can assert a simple post-condition
    // The sum will never exceed y after being reset
    __VERIFIER_assert(sum <= y);

    // The final state of sum depends on the number of times it exceeded y
    return 0;
}