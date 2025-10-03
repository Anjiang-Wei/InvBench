#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Custom Configuration:
names=a b max
beforeloop=
beforeloopinit=
precondition=a==0 && b>=0 && b<=100 && max==b
loopcondition=a<b
loop=if (a % 2 == 0) { max = a; } a++;
postcondition=max%2==0 || max==b
afterloop=
learners= conj
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int max = __VERIFIER_nondet_int();

    if (!(a == 0 && b >= 0 && b <= 100 && max == b)) {
        return 0;
    }
    while (a < b) {
        if (a % 2 == 0) {
            max = a;
        }
        a++;
    }
    __VERIFIER_assert(max % 2 == 0 || max == b);
    return 0;
}