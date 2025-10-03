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
Example program with constraints:
names=a b
precondition=a > 0 && b > a
loopcondition=b >= a
loop=a = a * 2; b = b - 3;
postcondition=a >= b && b < a * 2 - 1
learners=lin
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Precondition checks
    if (!(a > 0 && b > a)) {
        return 0;
    }

    // Main loop with constraints
    while (b >= a) {
        a = a * 2;
        b = b - 3;
    }

    // Postcondition to satisfy
    __VERIFIER_assert(a >= b && b < a * 2 - 1);

    return 0;
}