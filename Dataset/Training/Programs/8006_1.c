#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Program Explanation:
This program computes the sum of even numbers up to a given number `n`.
It includes a safety check to ensure the computed sum is non-negative.
*/
int main() {
    int n = __VERIFIER_nondet_int();
    int sum = 0;

    if (n < 0 || n > 100) {
        return 0;
    }

    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) { // Check if the number is even
            sum += i;
        }
    }

    __VERIFIER_assert(sum >= 0); // Ensure sum is non-negative
    return 0;
}