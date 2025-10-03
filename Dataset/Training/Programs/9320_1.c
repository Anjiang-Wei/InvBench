#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* New Configuration:
names=x y z
beforeloop=
beforeloopinit=x = 0; y = 0;
precondition=y >= 0
loopcondition=y < z
loop=x++; y += x;
postcondition=x <= z && y >= 0
afterloop=
*/

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    if (y < 0 || z < 0) {
        return 0; // Ensuring precondition
    }

    x = 0;
    y = 0;

    while (y < z) {
        x++;    // Increment x
        y += x; // Add x to y
    }

    __VERIFIER_assert(x <= z); // Guarantees x does not exceed z
    __VERIFIER_assert(y >= 0); // Guarantee non-negative y
    return 0;
}