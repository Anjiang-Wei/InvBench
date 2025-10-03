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
New Program:
names= a b n
beforeloop=
precondition= a == b && n > 0
loopcondition=
loop=a += 2; b += 2; n--;
postcondition= a == b && n >= 0
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    if (!(a == b && n > 0)) {
        return 0;
    }

    while (n > 0) {
        a += 2;
        b += 2;
        n--;
    }

    __VERIFIER_assert(a == b && n >= 0);
    return 0;
}