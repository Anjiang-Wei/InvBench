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
  Program description:
  This program initializes three integers, x, y, and z, with nondeterministic values.
  It aims to manipulate these variables in a loop to verify a certain postcondition.
  The precondition ensures that x and z are less than y and y is positive.
  The loop operates under the condition that both x and z are less than y.
  The logic in the loop increments x and decrements z, aiming to balance them.
  The postcondition checks if x has increased while ensuring z is kept non-negative.
*/

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    if (!(x < y && z < y && y > 0)) {
        return 0;
    }

    while (x < y && z < y) {
        x += 2;
        z -= 1;
        if (z < 0) {
            z = 0; // Ensures z remains non-negative
        }
    }

    __VERIFIER_assert(x >= y && z >= 0);
    return 0;
}