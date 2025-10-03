#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a = 0;
    int b;
    int threshold;

    // Simulate non-deterministic input
    b = __VERIFIER_nondet_int();
    threshold = __VERIFIER_nondet_int();

    // Assume conditions (like input contracts)
    assume_abort_if_not(threshold > 0 && threshold <= 100);
    assume_abort_if_not(b > 0 && b <= 10);

    // Loop for meaningful computation
    while (a < threshold) {
        // In each iteration, increase 'a' by a value 'b'
        a += b;

        // Check that 'a' never exceeds the threshold
        __VERIFIER_assert(a <= 1000);

        // Safeguard to ensure loop is not infinite for tool verification
        if (a > 1000) {
            abort();
        }
    }

    // Final assertion checks

    return 0;
}