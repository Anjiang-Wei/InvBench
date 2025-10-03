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
  Program performing constrained increments:
  Constraints:
  - Initial condition: a >= 0 && b == 0
  - Increments within loop: a and b values should always satisfy: 2 * a >= b
  Personal properties:
  - Loop iterates until b meets specific condition or exceeds maximum limit
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Initial constraints
    if (!(a >= 0 && b == 0)) {
        return 0;
    }

    while (__VERIFIER_nondet_bool() && b < 100) {
        a = a + 1;
        b = b + 2;

        // Maintain the condition: 2 * a >= b
        __VERIFIER_assert(2 * a >= b);
    }

    // Final property verification: ensuring that the final state fulfills expectations

    return 0;
}