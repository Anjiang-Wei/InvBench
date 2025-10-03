#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Initial conditions
    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);
    assume_abort_if_not(c == 0);

    int p1 = a, p2 = b;

    while (__VERIFIER_nondet_bool()) {
        if (__VERIFIER_nondet_bool()) {
            p1--;
        } else {
            p2--;
        }
        c++;

        // Ensure p1 and p2 never go negative
        assume_abort_if_not(p1 >= 0 && p2 >= 0);
    }

    // Post condition: c is the sum of decrements from p1 and p2
    __VERIFIER_assert(c == (a - p1) + (b - p2));

    return 0;
}