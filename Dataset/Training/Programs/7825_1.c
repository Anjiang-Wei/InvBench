#include <assert.h>
extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    if (a <= 0 || b <= 0) {
        return 0; // precondition
    }

    int x = a;
    int y = b;

    while (__VERIFIER_nondet_bool()) {
        if (__VERIFIER_nondet_bool()) {
            x = x - y;
        } else {
            y = y - x;
        }

        if (x <= 0) {
            x = a;
        }
        if (y <= 0) {
            y = b;
        }
    }

    __VERIFIER_assert(x > 0 && y > 0);
    return 0;
}