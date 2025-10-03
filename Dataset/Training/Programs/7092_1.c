#include <assert.h>

extern int __VERIFIER_nondet_int(void);

// Function to trigger an error
void reach_error() {
    assert(0);
}

// Custom assertion function
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // Gain necessary inputs
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();

    // Initial conditions
    if (n <= 0 || m <= 0) {
        return 0;
    }

    int x = 0, y = 0;

    // Loop to perform a non-trivial computation
    for (int i = 0; i < n; ++i) {
        x += i * m;
        y += m;
    }

    // Secondary loop
    int z = 1;
    while (z < y) {
        z *= 2;
    }

    // Verify computational requirements
    __VERIFIER_assert(x >= 0);

    return 0;
}