extern void abort(void);
#include <assert.h>
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = 1, b = 1;
    int m = __VERIFIER_nondet_int();

    assume_abort_if_not(m > 0 && m < 100);

    int res = 0;
    int i;

    for (i = 0; i < m; i++) {
        if (i % 2 == 0) {
            res += a;
        } else {
            res += b;
        }
    }

    __VERIFIER_assert(res >= m / 2 && res <= m);
    return 0;
}