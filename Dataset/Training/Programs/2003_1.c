#include <assert.h>
#include <stdio.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
  Description: This program aims to find a pair (m, n) such that
  the sum m + n is a constant value `targetSum`, starting from
  a pair (m, n) where m = targetSum and n = 0. The loop will swap
  increments between m and n as long as m is not less than n.
  The condition m + n = targetSum should always hold.
*/

int main() {
    int m = __VERIFIER_nondet_int();
    int n = 0; // Start with m = targetSum, n = 0
    int targetSum = m;

    // Precondition: m = targetSum && n = 0
    if (!(m == targetSum && n == 0)) {
        return 0;
    }

    while (__VERIFIER_nondet_bool()) {
        if (m >= n) {
            m--;
            n++;
        } else {
            break;
        }
    }

    // Postcondition: m + n = targetSum
    printf("Final values: m = %d, n = %d\n", m, n);
    __VERIFIER_assert(m + n == targetSum);

    return 0;
}