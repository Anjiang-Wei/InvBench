#include <assert.h>
#include <limits.h>

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
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int count = 0;

    assume_abort_if_not(a >= 0);           // 'a' should be non-negative
    assume_abort_if_not(b > 0 && b <= 10); // 'b' should be positive and not too large

    while (count < b) {
        sum += a;
        count++;
    }

    // Asserting the expected result: sum should be equal to a multiplied by b
    __VERIFIER_assert(sum == a * b);

    return 0;
}