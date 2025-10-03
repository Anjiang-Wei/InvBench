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
50.cfg:
names=i n product
beforeloop=
beforeloopinit=
precondition=i==1 && n>0 && n<=50 && product==1
loopcondition=i<=n
loop=product = product * i; i++;
postcondition=product>0
afterloop=
*/

int main() {
    int i = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    int product = __VERIFIER_nondet_int();

    if (!(i == 1 && n > 0 && n <= 50 && product == 1)) {
        return 0;
    }

    while (i <= n) {
        product = product * i;
        i++;
    }

    __VERIFIER_assert(product > 0);
    return 0;
}