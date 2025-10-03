#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

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

    // Precondition: assume a and b are non-negative and c = a + b
    if (!(a >= 0 && b >= 0 && c == a + b)) {
        return 0;
    }

    while (__VERIFIER_nondet_bool()) {
        if (__VERIFIER_nondet_bool()) {
            a++;
            c++;
        } else {
            b++;
            c++;
        }

        // We simulate a scenario where both a and b are incremented
        // The sum c should always match the sum of a and b
    }

    __VERIFIER_assert(c == a + b);

    return 0;
}