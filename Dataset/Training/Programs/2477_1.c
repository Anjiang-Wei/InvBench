#include <limits.h>

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int n, sum, term;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    sum = 0;
    term = 1;

    while (term <= n) {
        __VERIFIER_assert(sum == (term - 1) * term / 2);
        sum += term;
        term++;
    }

    // Confirm the sum equals n * (n + 1) / 2 after the loop

    return 0;
}