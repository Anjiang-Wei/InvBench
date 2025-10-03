// This program is a new verification task inspired by the given examples.
// It is designed to be analyzable by automated verification tools.
//
// SPDX-License-Identifier: Apache-2.0

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_verification_task.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int a, b, loop_limit, i;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);

    loop_limit = __VERIFIER_nondet_int();
    assume_abort_if_not(loop_limit >= 1 && loop_limit <= 10);

    i = 0;

    while (1) {
        // Ensure the loop invariant holds
        __VERIFIER_assert(a * b <= 100);

        if (!(i < loop_limit)) {
            break;
        }

        i++;
        a += 1;
        b -= 1;

        // Constraint to ensure loop does not run indefinitely
    }

    // Final assertion

    return 0;
}