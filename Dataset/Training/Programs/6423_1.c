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
names=a b n
precondition= (a==n) && (b==0) && (n>0)
loopcondition= a > 0 && b < n
loop=a--; b++;
postcondition= (a == 0) && (b == n)
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    if (!(a == n && b == 0 && n > 0)) {
        return 0;
    }

    while (a > 0 && b < n) {
        a--;
        b++;
    }

    __VERIFIER_assert(a == 0 && b == n);

    return 0;
}