#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Proposed Program Configuration:
names=a b c
precondition=a > 0 && b > 0 && c == 0
loopcondition=a > 0
loop=a--; b++; c=b-a;
postcondition=c>=0
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    if (!(a > 0 && b > 0 && c == 0)) {
        return 0;
    }
    while (a > 0) {
        a--;
        b++;
        c = b - a;
    }
    __VERIFIER_assert(c >= 0);
    return 0;
}