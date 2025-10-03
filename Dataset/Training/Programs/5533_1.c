#include <assert.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) { assert(0); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0 && m > 0); // Ensure n and m start positive

    int i = n;
    int j = m;
    int a = 0, b = 0;

    while (__VERIFIER_nondet_bool()) {
        // Ensure i and j don't decrease simultaneously
        if (i > 0 && j > 0) {
            // The sequence could be seen as a pattern where both variables evolve
            int step = __VERIFIER_nondet_int() % 2;
            if (step == 0) {
                a += i;
                b += j;
            } else {
                i--;
                j--;
            }
        } else if (i > 0) {
            i--;
        } else if (j > 0) {
            j--;
        }

        if (i <= 0 && j <= 0) {
            break;
        }
    }

    // At the end, a and b should contain sums accumualted
    // respectively and ensuring they do not ever become negative.
    __VERIFIER_assert(a >= 0 && b >= 0);

    return 0;
}