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

/* 30.cfg:
names=i x max
beforeloop=
beforeloopinit=
precondition=i==0 && x>=0 && max==0
loopcondition=i<50
loop=x = x + 2; if(x > max) max = x; i++;
postcondition=max >= 0
afterloop=
*/

int main() {
    int i = __VERIFIER_nondet_int();
    int x = __VERIFIER_nondet_int();
    int max = __VERIFIER_nondet_int();

    // Initial conditions
    if (!(i == 0 && x >= 0 && max == 0)) {
        return 0;
    }

    // Processing loop
    while (i < 50) {
        x = x + 2;
        if (x > max) {
            max = x;
        }
        i++;
    }

    // Checking postconditions
    __VERIFIER_assert(max >= 0);

    // Output final values
    printf("Final Values => i: %d, x: %d, max: %d\n", i, x, max);

    return 0;
}