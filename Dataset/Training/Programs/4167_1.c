/*
 * This program is designed to perform a number of operations based on
 * a series of inputs. It includes conditions and constraints that
 * can be verified by automated verification tools.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 10, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int perform_operations(int input);

int main() {
    int output = -1;

    while (1) {
        int input = __VERIFIER_nondet_int();
        if (input < 1 || input > 5) {
            return -1;
        }

        output = perform_operations(input);
    }
}

int perform_operations(int input) {
    int x = 0;
    int y = 0;
    int z;

    // Start a loop to modify x and y based on the input
    for (int i = 0; i < 10; ++i) {
        if (input == 1) {
            x += 2;
            y += 1;
        } else if (input == 2) {
            x -= 1;
            y += 3;
        } else if (input == 3) {
            x *= 2;
            y /= 2;
        } else if (input == 4) {
            x = x + y;
            y = y - x;
        } else {
            x = x - y;
            y = x + y;
        }
    }

    // Some constraint to check with assertions
    z = x + y;
    __VERIFIER_assert(z >= 0);

    // Return value to determine the flow based on specific conditions
    if (x > 10 && y < 5) {
        return 1;
    }
    if (x < 0 || y < 0) {
        return -1;
    }
    return 0;
}