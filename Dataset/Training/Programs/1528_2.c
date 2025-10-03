#include <stdio.h>
#include <stdlib.h>

// Function prototypes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

int __VERIFIER_nondet_int(void) {
    return rand() % 10; // Simulating nondeterministic integer generation
}

int main() {
    int x = 0;
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    assume_abort_if_not(y > 0 && z > 0); // Ensure y and z are positive

    int counter = 0;
    while (counter < 10) {
        if (x <= 20) {
            x += y;
        } else {
            x -= z;
        }
        counter++;

        // Assertions to be verified
        __VERIFIER_assert(x <= 100);
    }

    // Final assertion to check the expected result

    return 0;
}