#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Example Config:
names= a b
precondition=a==2 && b==2
loopcondition=
loop=a=a+b; b=a-b;
postcondition=b>=2
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    if (!(a == 2 && b == 2)) {
        return 0;
    }

    while (__VERIFIER_nondet_bool()) {
        a = a + b;
        b = a - b; // Swap operation to include an arithmetic twist
    }

    __VERIFIER_assert(b >= 2);
    return 0;
}