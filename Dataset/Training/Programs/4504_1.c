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

    // Ensure initial conditions for analysis
    if (!(a >= 0 && b >= 0 && a == 3 * b)) {
        return 0;
    }

    while (a > 0) {
        if (b > 0) {
            a -= 2;
            b -= 1;
        } else {
            break;
        }
    }

    // Postcondition to be checked
    __VERIFIER_assert(b == 0 || a <= 0);

    return 0;
}