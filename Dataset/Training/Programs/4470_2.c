#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, temp;

    // Generate nondeterministic values
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Ensure non-negative values
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    // Euclidean algorithm
    while (b != 0) {

        // Update a and b
        a = b;
        b = temp;
    }

    // Post-condition: The variable 'a' should be the GCD
    __VERIFIER_assert(a >= 0); // GCD of non-negative integers should be non-negative

    return 0;
}