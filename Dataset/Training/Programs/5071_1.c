#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Custom program:
names=a b n
precondition=a == 0 && b == 0 && n >= 0
loopcondition=n > 0
loop=a = a + 1; b = b + a; n--;
postcondition=b == a * (a + 1) / 2
learners=conj
*/

int main() {
    int a = 0;
    int b = 0;
    int n = __VERIFIER_nondet_int();

    if (!(n >= 0)) {
        return 0;
    }
    while (n > 0) {
        a = a + 1;
        b = b + a;
        n--;
    }
    __VERIFIER_assert(b == a * (a + 1) / 2);
    return 0;
}