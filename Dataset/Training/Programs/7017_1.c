#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Program:
   - Starts with x, y, z all initialized to zero.
   - In the loop, z is incremented, and based on its parity, x or y is also incremented.
   - The loop continues until a nondeterministic boolean condition ends it.
   - Postcondition checks if the quantity `x + y + z` equals `z`.
*/
int main() {
    int x = 0;
    int y = 0;
    int z = 0;

    while (__VERIFIER_nondet_bool()) {
        z++;
        if (z % 2 == 0) {
            x++;
        } else {
            y++;
        }
    }

    // Postcondition: x + y + z should be equal to 2*z, since x + y = z
    // under the transformation logic defined in the loop.
    __VERIFIER_assert(x + y == z);

    return 0;
}