#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    int result = 1;

    // Precondition
    if (n < 0) {
        return 0;
    }

    // Compute factorial using iterative approach
    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    // Postcondition: result should always be positive for n >= 0
    __VERIFIER_assert(result > 0);

    return 0;
}