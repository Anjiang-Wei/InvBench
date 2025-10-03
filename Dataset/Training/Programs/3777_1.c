#include <assert.h>
#include <stdio.h>

void reach_error(void) {
    assert(0); // This is used to indicate an error state
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Description:
   The program initializes a sequence, where a starts from a non-deterministic value.
   It checks that for every iteration a certain relationship holds between 'a', 'b', and 'sum',
   which is initially non-deterministically set. The process continues while a random
   condition (defined by a non-deterministic variable) is true.
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int init_a = a;

    if (a < 0) {
        return 0; // Start with a non-negative initial value for demonstration
    }
    if (b < 0) {
        return 0; // Ensure b is also non-negative
    }

    int sum = 0;

    // Simulating a sequence alteration: increase b, check relationship and sum
    while (__VERIFIER_nondet_bool() && a > 0) {
        b += 2; // Increment b
        sum += b;
        a--; // Decrement a

        // The program ensures that sum is always at least b times some factor
        __VERIFIER_assert(sum >= b);
    }

    // Post-loop validation to capture expected relationship

    printf("Computation complete\n");

    return 0;
}