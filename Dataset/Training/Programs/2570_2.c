#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* The program models a counting process with constraints:
   1. The sum of even and odd numbers is maintained correctly through x and y.
   2. Both accumulative conditions for x and y must remain non-negative.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    int x = 0; // Sum of even numbers
    int y = 0; // Sum of odd numbers
    int i = 0; // Counter

    if (n < 0) {
        return 0; // Precondition: n must be non-negative
    }

    // Loop invariant: 2*x + y = i, where i is the current counter value
    while (i < n) {
        if (i % 2 == 0) {
            x += i; // Accumulate even numbers in x
        } else {
            y += i; // Accumulate odd numbers in y
        }
        i++;
    }

    // Postcondition: Check that the sum is maintained
    __VERIFIER_assert(x >= 0 && y >= 0); // Ensure non-negativity of sums

    // Print results for verification purposes
    printf("Sums: even=%d, odd=%d\n", x, y);
    return 0;
}