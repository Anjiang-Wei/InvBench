#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* My_New_Program.cfg:
names= a b c
beforeloop=
beforeloopinit=
precondition= a==0 && b>=0 && c==1
loopcondition=b > 0
loop=a = a + c; b--; c = c * 2;
postcondition=a == (c - 1)
afterloop=
learners= conj
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    if (!(a == 0 && b >= 0 && c == 1)) {
        return 0;
    }

    while (b > 0) {
        a = a + c;
        b--;
        c = c * 2;
    }

    // Ensure that `a` is equal to 2^b after the loop finishes, note: 2^b = c/2 because c doubles every iteration.
    __VERIFIER_assert(a == (c - 1));

    return 0;
}