#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* New Program:
names= a b c
precondition= a > 0 && b > 0
loopcondition= c < a * b
logic= a * b - c > 0
loop= if (c % 2 == 0) c += a; else c += b;
postcondition= c >= a && c >= b
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = 0; // Initialize c to zero

    // Assume precondition
    if (!(a > 0 && b > 0)) {
        return 0;
    }

    // Loop with a logic-driven exit condition
    while (c < a * b) {
        if (c % 2 == 0) {
            c += a; // If c is even, increment by a
        } else {
            c += b; // If c is odd, increment by b
        }
    }

    // Postcondition check
    __VERIFIER_assert(c >= a && c >= b);

    return 0;
}