#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Preconditions
    assume_abort_if_not(a >= 0 && b >= 0 && m > 0 && n > 0);
    assume_abort_if_not(a < m && b < n);

    int counter = 0;

    while (a < m && b < n) {
        if (__VERIFIER_nondet_int()) {
            a++;
        } else {
            b++;
        }
        counter++;
    }

    __VERIFIER_assert(counter <= m + n);

    return 0;
}