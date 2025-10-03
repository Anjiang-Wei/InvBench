#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* This program models a scenario with two variables, a and b.
   It initializes them from arbitrary non-deterministic values
   and implements a loop that modifies them against a set of
   conditions. The program will assert certain constraints are
   met after the loop has been executed.

   - Variables must start within a specified precondition.
   - The loop iterates whilst a certain condition on a holds.
   - Postconditions should hold with constraints between a and b.
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Ensure initial conditions hold
    if (!(a >= -50 && a <= 50)) {
        return 0;
    }
    if (!(b >= 0 && b <= 100)) {
        return 0;
    }

    while (a >= 0) {
        _Bool dec_a = __VERIFIER_nondet_bool();
        if (dec_a) {
            a -= 5;
        } else {
            a -= 2;
            b += 3;
        }

        if (b > 200) {
            b -= 50; // Prevent b from growing indefinitely
        }
    }

    // At this point, ensure postconditions are satisfied
    __VERIFIER_assert(a < 0 && b >= 0 && b <= 200);

    return 0;
}