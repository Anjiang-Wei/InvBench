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
 This program computes the sum of all even numbers
 less than or equal to a given non-negative integer, n.
 The program ensures that the sum is a non-negative number.

 Loop invariant guarantees that integers added to the sum are even.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int i = 0;

    // We constraint n to be non-negative
    if (n < 0) {
        return 0;
    }

    while (i <= n) {
        if (i % 2 == 0) {
            sum += i;
        }
        i++;
    }

    // Asserting that sum should be non-negative after the loop
    __VERIFIER_assert(sum >= 0);

    return 0;
}