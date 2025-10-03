#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Description:
The program initializes three integer variables a, b and c with nondeterministic values.
Precondition requires c > 0.
The loop iteratively decrements 'a' while the sum of 'a' and 'b' is less than c.
Postcondition checks if either 'a' or 'b' has to be non-negative.
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Precondition
    if (!(c > 0)) {
        return 0;
    }

    // Loop to adjust 'a' while 'a + b' is less than 'c'
    while (a + b < c) {
        if (a >= 0) {
            a--;
        } else {
            b++;
        }
    }

    // Postcondition which should be satisfied
    __VERIFIER_assert(a >= 0 || b >= 0);

    return 0;
}