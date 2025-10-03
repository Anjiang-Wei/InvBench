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
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Precondition: m >= 0, n >= 0
    if (!(m >= 0 && n >= 0)) {
        return 0;
    }

    int sum = 0;
    int product = 1;
    for (int i = 0; i < m; i++) {
        if (__VERIFIER_nondet_bool()) {
            sum += n;
        } else {
            sum -= n;
        }
    }

    while (__VERIFIER_nondet_bool()) {
        if (a > b) {
            a -= b;
        } else if (a < b) {
            b -= a;
        } else {
            break;
        }
        product *= 2;
    }

    __VERIFIER_assert(product >= 1);

    return 0;
}