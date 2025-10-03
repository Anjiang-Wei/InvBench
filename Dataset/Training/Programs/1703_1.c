#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* New Program:
names=a b c
beforeloop=
beforeloopinit=
precondition=a==0 && b==0 && c>0
loopcondition=b < c
loop=a += b; b++;
postcondition=a >= 0
afterloop=
learners= conj
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    if (!(a == 0 && b == 0 && c > 0)) {
        return 0;
    }

    while (b < c) {
        a += b;
        b++;
    }

    __VERIFIER_assert(a >= 0);
    return 0;
}