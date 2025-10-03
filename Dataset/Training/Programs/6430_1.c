#include <assert.h>
#include <stdlib.h>

void reach_error(void) {
    assert(0);
}

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int M = __VERIFIER_nondet_int();
    int P = __VERIFIER_nondet_int();

    assume_abort_if_not(M > 0 && P > 0);
    assume_abort_if_not(M <= 1000 && P <= 1000);

    long long factorial = 1;
    long long power = 1;
    int i;

    for (i = 1; i <= M; i++) {
        factorial = factorial * i;
    }

    for (i = 0; i < P; i++) {
        power = power * M;
    }

    __VERIFIER_assert(factorial > 0);

    return 0;
}