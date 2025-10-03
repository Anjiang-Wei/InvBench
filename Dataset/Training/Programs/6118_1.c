#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 5, "reach_error"); }
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
    int a, b, c, result, steps;

    // Nondeterministic input values
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Constraint assumptions
    assume_abort_if_not(a >= 1 && b >= 1);

    c = 0;
    result = 0;
    steps = 0;

    // Loop with a certain condition
    while (steps < 500) {
        result = result + a + b + c;

        if (steps % 3 == 0) {
            c += 2;
        } else if (steps % 3 == 1) {
            a -= 1;
            assume_abort_if_not(a >= 0); // Preventing negative values
        } else {
            b -= 1;
            assume_abort_if_not(b >= 0); // Preventing negative values
        }

        // Breaking condition
        if (a == 0 || b == 0) {
            break;
        }

        steps++;
    }

    // Verification for expected condition after loop
    __VERIFIER_assert(result >= 0);
    return 0;
}