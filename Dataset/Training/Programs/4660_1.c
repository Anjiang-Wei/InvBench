#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* New program:
names= a b c total
beforeloop=
beforeloopinit=
precondition=a==0 && b==0 && total==0 && c>=0
loopcondition=a <= c
loop=total += a + b; a++; b++;
postcondition=total >= 0
afterloop=
learners= conj
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int total = __VERIFIER_nondet_int();

    if (!(a == 0 && b == 0 && total == 0 && c >= 0)) {
        return 0;
    }

    while (a <= c) {
        total += a + b;
        a++;
        b++;
    }

    __VERIFIER_assert(total >= 0);

    return 0;
}