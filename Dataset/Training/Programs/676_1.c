#include <assert.h>
#include <stdbool.h>
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
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;
    int steps = 0;

    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    while (steps < 10) {
        if (steps % 2 == 0) {
            sum += a;
            product *= b;
        } else {
            sum += b;
            product *= a;
        }
        steps++;
    }

    // Ensuring the invariants after loop completion
    __VERIFIER_assert(sum > 0);

    return 0;
}