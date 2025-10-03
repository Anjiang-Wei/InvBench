// New Verification Task
// This program aims to simulate a simple counting system where
// each component gets incremented based on specific conditions.

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
extern _Bool __VERIFIER_nondet_bool(void);

int main() {
    int a = 0, b = 0, threshold = 100;
    int count = __VERIFIER_nondet_int();

    // Ensure non-deterministic input is within a plausible range
    if (count < 0) {
        count = 0;
    } else if (count > 100) {
        count = 100;
    }

    while (1) {
        if (__VERIFIER_nondet_bool()) {
            a++;
        } else {
            b++;
        }

        if (a + b > threshold) {
            break;
        }

        __VERIFIER_assert(a + b <= 2 * threshold);

        if (count > 0) {
            count--;
        } else {
            break;
        }
    }

    return 0;
}