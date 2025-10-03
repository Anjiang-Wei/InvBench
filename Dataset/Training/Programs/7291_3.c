#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

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
    int x, y, z;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    z = __VERIFIER_nondet_int();

    // Assume initial conditions
    assume_abort_if_not(x >= 0 && x <= 10);
    assume_abort_if_not(y >= 0 && y <= 10);
    assume_abort_if_not(z >= 0 && z <= 10);

    while (x < 20 && y < 20) {
        int choice = __VERIFIER_nondet_int();
        if (choice) {
            x = x + 1;
            y = y + 2;
        } else {
            x = x + 2;
            y = y + 1;
        }

        // Adding constraint: z will increment based on x and y movements
        if (x + y < 30) {
            z = z + 1;
        } else {
            z = z - 1;
        }

        // Perform some verification
    }

    // Final check
    __VERIFIER_assert(x < 30 && y < 30);
    return 0;
}