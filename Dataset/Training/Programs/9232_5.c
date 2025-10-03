#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // Variables
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();

    // Precondition
    if (!(a >= 0 && b >= 0 && n >= 1 && m >= n)) {
        return 0;
    }

    // Initialize
    int sumA = 0, sumB = 0, prodA = 1, prodB = 1;

    // Computation loop
    for (int i = 0; i < n; i++) {
        sumA += a;
        sumB += b;
        prodA *= (a + 1);
        prodB *= (b + 1);

        // Invariant assertion
    }

    // Postcondition: Check if the product and sum relations hold

    // Another loop for manipulating arrays under conditions
    int array[100];
    for (int j = 0; j < m; j++) {
        if (j < n) {
            array[j] = j * j;
        } else {
            array[j] = j + a;
        }

        // Array value assertion
        __VERIFIER_assert(array[j] >= j);
    }

    // Final condition checks
    if (prodA > prodB) {
    } else {
    }

    return 0;
}