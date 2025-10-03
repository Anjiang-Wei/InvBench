#include <assert.h>
void reach_error() { assert(0); }

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
    int n;
    int sum, prod;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    sum = 0;
    prod = 1; // To avoid multiplication by zero

    for (int i = 0; i < n; i++) {
        sum += i;
        prod *= (i + 1);
    }

    // The loop should result in sum being the summation of natural numbers and prod being factorial
    __VERIFIER_assert((n == 0 && prod == 1) || (n > 0 && prod != 0));

    return 0;
}