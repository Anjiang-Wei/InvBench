#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Initial constraint: a > b, c = 2*b
    if (!(a > b && c == 2 * b)) {
        return 0;
    }

    int x = 0;

    while (a > 0 && b > 0) {
        if (x % 2 == 0) {
            a -= 1;
        } else {
            b -= 1;
            c -= 2;
        }
        x++;
        __VERIFIER_assert(c == 2 * b); // Ensure invariant property of c
    }

    // After the loop b and c can be zero, verify one possible condition
    if (b == 0) {
        __VERIFIER_assert(c == 0);
    }

    return 0;
}