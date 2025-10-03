extern void abort(void);
#include <assert.h>
void reach_error() { assert(0); }

extern unsigned int __VERIFIER_nondet_uint(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    unsigned int m, n, sum, product, count;

    m = __VERIFIER_nondet_uint();
    assume_abort_if_not(m >= 1 && m <= 50);

    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 1 && n <= 50);

    sum = 0;
    product = 1;
    count = 0;

    while (count < m) {
        sum += n;
        product *= 2;

        if (product > 1000) {
            break;
        }

        count++;
    }

    __VERIFIER_assert(product <= 1024); // Because 2^10 = 1024 and our loop is limited to run max 50 times

    return 0;
}