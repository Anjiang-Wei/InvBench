#include <stdio.h>
#include <stdlib.h>

/*
Contributors:
- A hypothetical C program inspired by typical verification challenges
- Focusing on the relationship between exponential growth and comparison with limits
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
int __VERIFIER_nondet_int(void) {
    return rand();
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void reach_error() { __assert_fail("0", "solution.c", 8, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int i, x, y, n;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 20); // Restrict n between 1 and 20

    x = 1;
    y = 1;

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            x = x * 2; // Exponential growth in x
        } else {
            y = y + i; // Linear increase in y
        }

        // Check for intended properties
        __VERIFIER_assert(y > 0);

        // Constraint logic example: ensure x is always greater than y
        assume_abort_if_not(x > y);
    }

    return 0;
}