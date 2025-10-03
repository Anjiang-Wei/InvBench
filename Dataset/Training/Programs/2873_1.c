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
names=x y maximum_product
beforeloop=
beforeloopinit=
precondition=x>=0 && y>=0 && maximum_product==0
loopcondition=x<100
loop=y=y+x; maximum_product=(maximum_product<y)?y:maximum_product; x++
postcondition=maximum_product>=0
afterloop=
learners= conj
*/

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int maximum_product = 0;

    if (!(x >= 0 && y >= 0 && maximum_product == 0)) {
        return 0;
    }

    while (x < 100) {
        y = y + x;
        maximum_product = (maximum_product < y) ? y : maximum_product;
        x++;
    }
    __VERIFIER_assert(maximum_product >= 0);
    return 0;
}