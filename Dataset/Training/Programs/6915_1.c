#include <assert.h>

extern void abort(void);
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

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
    int c = 0;
    int limit = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && b >= 0);
    assume_abort_if_not(limit > 0);

    for (int i = 0; i < limit; i++) {
        if (c % 2 == 0) {
            a += i;
        } else {
            b += i;
        }
        c++;
    }

    __VERIFIER_assert(a >= 0 && b >= 0);
    return 0;
}