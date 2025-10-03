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
beforeloop=
beforeloopinit=
precondition= a > 0 && b > 0 && c == 0
loopcondition= a > 0
loop= if(__VERIFIER_nondet_bool()) { a--; b++; } else { a--; c++; }
postcondition= (b + c) > 0
afterloop=
learners= exploration
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = 0;

    if (!(a > 0 && b > 0 && c == 0)) {
        return 0;
    }

    while (a > 0) {
        if (__VERIFIER_nondet_bool()) {
            a--;
            b++;
        } else {
            a--;
            c++;
        }
    }

    __VERIFIER_assert((b + c) > 0);
    return 0;
}