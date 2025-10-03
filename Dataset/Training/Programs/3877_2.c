#include <stdio.h>
#include <stdlib.h>

// External functions used for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

// Function to assert conditions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function to simulate non-deterministic choices
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Main program function
int main() {
    int a, b, c, n;

    // Non-deterministic initialization
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0);
    assume_abort_if_not(a >= 0 && b >= 0 && c >= 0);

    int x = a;
    int y = b;
    int z = c;

    int i = 0;

    // Loop with meaningful computation
    while (i < n) {
        // Compute some basic operations to observe behavior
        x = x + y;
        y = y + z;
        z = z + x;

        // Increment loop index
        i++;

        // Assert specific properties during the computation
    }

    // Final condition check
    __VERIFIER_assert((x + y + z) >= (a + b + c));

    return 0;
}