#include <assert.h>
#include <stdbool.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error() {
    assert(0);
}

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

// This program computes the sum of odd numbers
// until a certain threshold value of n.
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    int i = 1;
    int sum_odd = 0;
    int count = 0; // number of odd numbers added

    while (__VERIFIER_nondet_bool() && i <= n) {
        sum_odd += i;
        count++;
        i += 2; // move to the next odd number
    }

    // Using a formula for sum of first k odd numbers
    // The sum of first k odd numbers is k^2
    __VERIFIER_assert(sum_odd == count * count);

    return 0;
}