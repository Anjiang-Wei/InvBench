#include <stdio.h>
#include <stdlib.h>

// Function prototypes for external and error handling functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to ensure certain conditions hold
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, m, n;
    // Initialize variables with non-deterministic values with constraints
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 10);

    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 10);

    m = __VERIFIER_nondet_int();
    assume_abort_if_not(m > 0 && m <= 10);

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 10);

    int sum = a + b;
    int steps = 0;

    // Loop computing a pattern based on sum and m, n
    while (steps < m * n) {

        if (steps % 2 == 0) {
            sum += m;
        } else {
            sum -= n;
        }

        steps++;
    }

    // Final assertion to verify key constraints after computation
    __VERIFIER_assert(sum >= (a + b) - (n * (steps / 2)));

    return 0;
}