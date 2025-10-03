#include <stdio.h>
#include <stdlib.h>

// Abstract functions for verification, representing non-deterministic behavior
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprog.c", 8, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Verification assertion
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

// Program logic
int main() {
    int a, b, m, n;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assume constraints
    assume_abort_if_not(a >= 0 && b >= 0 && m >= 0 && n >= 0);
    assume_abort_if_not(a <= 10 && b <= 10 && m <= 10 && n <= 10);

    int sum = 0;
    int diff = 0;
    int step = 0;

    // Main computation loop
    while (step <= m) {
        sum += a;
        diff -= b;

        if (step % 2 == 0) {
            sum += n;
        } else {
            diff -= n;
        }

        step++;
    }

    // Check constraints
    __VERIFIER_assert(diff <= 0);

    // Final verification condition

    return 0;
}