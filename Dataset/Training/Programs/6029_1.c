#include <stdbool.h>
#include <stdlib.h>

// Forward declarations of functions used in verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sample_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Verification-specific assertion
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    // Initialization
    int limit = __VERIFIER_nondet_int();
    int a = 0, b = 1, c = 0; // Fibonacci sequence initialization

    // Ensure the limit is positive to avoid infinite loop
    assume_abort_if_not(limit > 0 && limit < 1000);

    // Compute Fibonacci sequence up to limit
    while (c < limit) {
        // Valid Fibonacci properties
        __VERIFIER_assert(a <= b && b >= 0 && c <= limit);

        c = a + b;
        a = b;
        b = c;
    }

    // Post-condition: Fibonacci sequence calculated without overflow and stays within limits

    return 0;
}