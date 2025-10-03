#include <stdio.h>
#include <stdlib.h>

// Simulates external functions commonly used in verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated_example.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int count = 0;
    int x = 0;
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    // Constraint for nondeterministic inputs
    assume_abort_if_not(y >= 0 && y <= 100);
    assume_abort_if_not(z >= 0 && z <= 100);

    while (count < 20) {
        x = x + y - z;
        __VERIFIER_assert(x <= (y * count + 100));
        if (x < 0) {
            x = -x; // Ensure x is non-negative
        }
        count++;
    }

    // Post-condition assertions

    printf("Final value of x: %d\n", x);
    return 0;
}