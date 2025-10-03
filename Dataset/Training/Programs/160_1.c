#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* New Concept:
names= a b product
beforeloop=
beforeloopinit=
precondition=a >= 0 && b >= 0 && product == 0 && a <= 100
loopcondition=b > 0
loop=product += a; b--;
postcondition=product >= 0
afterloop=
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int product = __VERIFIER_nondet_int();

    if (!(a >= 0 && b >= 0 && product == 0 && a <= 100)) {
        return 0;
    }

    while (b > 0) {
        product += a;
        b--;
    }

    __VERIFIER_assert(product >= 0);
    return 0;
}