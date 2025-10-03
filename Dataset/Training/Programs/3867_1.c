#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Program description:
This program calculates the sum of even numbers and the sum of odd numbers from 0 up to a non-deterministically chosen positive integer n.
The program then verifies if the total sum is equal to the sum of both (even and odd) calculated sums.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    if (!(n >= 0)) {
        return 0;
    }

    int even_sum = 0;
    int odd_sum = 0;
    int total_sum = 0;
    int i = 0;

    // Calculate sums of even and odd numbers
    while (i <= n) {
        if (i % 2 == 0) {
            even_sum += i;
        } else {
            odd_sum += i;
        }
        total_sum += i;
        i++;
    }

    // Verify if the calculated sums are correct
    __VERIFIER_assert(even_sum + odd_sum == total_sum);

    return 0;
}