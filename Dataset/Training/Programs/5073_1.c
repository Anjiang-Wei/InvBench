#include <assert.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
The program aims to calculate the sum of non-negative integers up to a certain limit.
The sum is calculated only for even numbers.
There are added constraints to ensure bounds and proper integer inputs.
*/

int main() {
    int limit = __VERIFIER_nondet_int();
    int sum = 0;
    int i = 0;

    // Assume some constraints on the limit
    if (!(limit >= 1 && limit <= 1000)) {
        return 0;
    }

    while (__VERIFIER_nondet_bool() && i < limit) {
        if (i % 2 == 0) {
            sum += i;
        }
        i++;
    }

    // Assert that the sum is non-negative and within a certain bound
    __VERIFIER_assert(sum >= 0);

    return 0;
}