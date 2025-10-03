#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
This program checks a sequence of operations on two variables a and b.
It ensures that a certain condition is maintained throughout the loop
and verifies a final outcome.

initial conditions:
a + b = c && a >= 0 && b >= 0 && c >= 0

loop conditions:
while a > 0
    decrement a, increment b, update c

postcondition:
b >= c
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    if (!(a + b == c && a >= 0 && b >= 0 && c >= 0)) {
        return 0;
    }

    while (a > 0) {
        a--;
        b++;

        // Additional computation and check
        if (c > a + b) {
            c = a + b; // update c if it's greater than a+b
        }
    }

    // Verify the final condition
    __VERIFIER_assert(b >= c);

    return 0;
}