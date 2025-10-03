#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    int result = 0;
    assume_abort_if_not(n >= 0 && n <= 1000); // Set some realistic bounds for n

    // Simple computation using an arithmetic series
    // result = sum of first n even numbers
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            result += i;
        }
    }

    // Assert that the result is non-negative as it is a sum of non-negative integers
    __VERIFIER_assert(result >= 0);

    return 0;
}