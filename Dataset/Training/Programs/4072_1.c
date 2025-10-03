#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Structure Explanation:
names= a b sum
beforeloop=
beforeloopinit=
precondition= a == b && a >= 0 && sum == 0
loopcondition=b > 0
loop=a--; b--; sum++;
postcondition= sum == initial_b
afterloop=
learners= conj
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;

    if (!(a == b && a >= 0 && sum == 0)) {
        return 0;
    }
    int initial_b = b; // track initial value of b

    while (b > 0) {
        a--;
        b--;
        sum++;
    }

    __VERIFIER_assert(sum == initial_b);
    return 0;
}