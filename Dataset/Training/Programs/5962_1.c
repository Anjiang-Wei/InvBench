#include <assert.h>
#include <stdbool.h>

// Function to report an error
void reach_error(void) { assert(0); }

// A function that can assume a condition or abort
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// An assertion function for verification
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// External nondeterministic int function
extern int __VERIFIER_nondet_int(void);

int main() {
    int a = 0, b = 0, x, y;
    int sum = 0;

    // Get nondeterministic values for x and y
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    // Assuming x and y are non-negative and y > 0
    assume_abort_if_not(x >= 0 && y > 0);

    // A loop that adds numbers from 1 to x (inclusive) in jumps of y
    for (int i = 0; i <= x; i += y) {
        sum += i;
        a += 1;
    }

    // A condition to trigger an error in case of incorrect computation
    __VERIFIER_assert(sum == (a * (a - 1) / 2) * y || (a - 1) * y <= x);

    return 0;
}