#include <assert.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
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
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    assume_abort_if_not(m >= 0 && m <= 10);
    assume_abort_if_not(n >= 0 && n <= 10);

    int sum = 0;
    int product = 1;

    for (int i = 0; i < m; i++) {
        sum += i + n;
    }

    int j = 0;
    while (j < n) {
        product *= j + m;
        j++;
    }

    // After the loop, the conditions to be verified
    __VERIFIER_assert(product != 0 || n == 0 || (0 <= m && m <= 10));

    return 0;
}