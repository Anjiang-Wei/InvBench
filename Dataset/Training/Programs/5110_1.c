#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Program Description:
This program performs a simple arithmetic operation with constraints.
- It starts with an initial state where x is a non-deterministic integer and y is initially set to double the value of x.
- In the loop, x is incremented by 3 and y is incremented by 6.
- The program continues this until a non-deterministic condition is false.
- Finally, it asserts if y always remains double the value of x, proving that the initial relation remains invariant.
*/

int main() {
    int x = __VERIFIER_nondet_int();
    int y = 2 * x; // y is always twice x at the start

    while (__VERIFIER_nondet_bool()) {
        x += 3; // Increment x by 3
        y += 6; // Increment y by 6
    }

    // Assert that y is always twice x
    __VERIFIER_assert(y == 2 * x);
    return 0;
}