#include <assert.h>
#include <stdbool.h>

// Custom abort and assert functions
extern void abort(void);
void reach_error() { assert(0); }

// Function to ensure conditions and trigger error if not met
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int();

// Helper function for breaking a loop conditionally
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = 0, b = 0, c = 0;
    int n = __VERIFIER_nondet_int();

    // Assuming that n should be within a reasonable range
    assume_abort_if_not(n >= 0 && n <= 1000);

    // Ensure a simple relationship throughout the loop
    while (a < n) {
        a++;
        b += 2 * a;
        c += 3 * b - a;
    }

    // Perform checks after the loop
    __VERIFIER_assert(a == n);         // a should have iterated fully
    __VERIFIER_assert(b >= 2 * n);     // b should accumulate in steps of 2*a
    __VERIFIER_assert(c >= 3 * b - a); // c should be consistent based on its accumulation logic

    // This program ends without errors if the asserts hold
    return 0;
}