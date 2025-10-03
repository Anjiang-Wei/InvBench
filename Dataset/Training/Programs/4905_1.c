#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* My C program:
names= a b step
precondition= a >= 0 && b >= 0 && b < 100
loopcondition=step-- > 0 && a < 100
loop=a += b; b = (b + 1) % 100;
postcondition=a >= 0
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int step = __VERIFIER_nondet_int();

    if (!(a >= 0 && b >= 0 && b < 100 && step >= 0)) {
        return 0;
    }

    while (step-- > 0 && a < 100) {
        a += b;
        b = (b + 1) % 100;
    }

    __VERIFIER_assert(a >= 0);
    return 0;
}