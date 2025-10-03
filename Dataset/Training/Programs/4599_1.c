#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Constraint Precondition
    if (!(a >= 0 && b >= 1 && c == 0)) {
        return 0;
    }

    // Loop performing arithmetic operations
    while (a < b) {
        if (a % 2 == 0) {
            c += a;
        } else {
            c -= a;
        }
        a++;
    }

    // Constraint Postcondition
    __VERIFIER_assert(c <= (b * (b - 1)) / 2);
    return 0;
}