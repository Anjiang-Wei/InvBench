#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Custom CFG:
names=i count isPositive
beforeloop=
beforeloopinit=
precondition=i==0 && count==0 && isPositive==1
loopcondition=i<200 && isPositive
loop=count += i; i += 2; isPositive = (i % 5 != 0);
postcondition=count >= 0
afterloop=
learners= conj
*/
int main() {
    int i = __VERIFIER_nondet_int();
    int count = __VERIFIER_nondet_int();
    _Bool isPositive = __VERIFIER_nondet_bool();

    if (!(i == 0 && count == 0 && isPositive == 1)) {
        return 0;
    }

    while (i < 200 && isPositive) {
        count += i;
        i += 2;
        isPositive = (i % 5 != 0);
    }

    __VERIFIER_assert(count >= 0);
    return 0;
}