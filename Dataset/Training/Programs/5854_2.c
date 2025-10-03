#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int limit = __VERIFIER_nondet_int();
    if (limit <= 0 || limit > 10000) {
        return 0;
    }

    int a = 0;
    int b = 0;
    int c = 0;

    while (__VERIFIER_nondet_bool()) {
        if (__VERIFIER_nondet_bool()) {
            if (a < limit) {
                a++;
            } else {
                limit /= 2; // Halve the limit when its reached
            }
        }

        if (__VERIFIER_nondet_bool()) {
            if (b < a) {
                b++;
            }
        }

        if (__VERIFIER_nondet_bool()) {
            if (c < b) {
                c++;
            } else {
                b -= c; // Reset b to avoid infinite loop
                c = 0;
            }
        }
    }

    __VERIFIER_assert(a >= b);
    return 0;
}