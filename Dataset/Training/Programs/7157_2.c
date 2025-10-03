#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int();

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int x = 0;
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    // Constraint to make sure y and z have specific properties
    assume_abort_if_not(y >= 0 && y <= 10);
    assume_abort_if_not(z >= 0 && z <= 20);

    // Initialize a count to control loop iterations
    int count = 0;

    while (count < 10) {
        if ((x + y) % 2 == 0) {
            x += y + 2 * z;
        } else {
            x -= (y + z);
        }
        count++;
        // Ensure x remains within a reasonable bound
    }

    // Final assertion to verify a condition on the result
    __VERIFIER_assert((x % 2 == 0) || (x % 2 == 1));

    printf("x: %d\n", x); // For possible visual feedback
    return 0;
}