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

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* New Program:
   This program implements a variation of the Collatz conjecture logic. It is
   designed to randomly take a number and transform it under the condition that
   if the number is odd multiply it by 3 and add 1, if even simply divide it by 2.
   The program asserts specific properties at each step of the transformation.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1); // Ensure n is a positive integer.

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        __VERIFIER_assert(n > 0); // After operation, n must remain a positive integer.
    }

    printf("Completed Collatz sequence.\n");
    return 0;
}