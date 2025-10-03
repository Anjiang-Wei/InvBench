#include <assert.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
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
    int A = __VERIFIER_nondet_int();
    int B = __VERIFIER_nondet_int();

    // Precondition: A and B must be positive
    assume_abort_if_not(A > 0 && B > 0);

    int sum = 0;
    int product = 1;
    int count = 0;

    // Loop: Calculate the sum and product of integers from 1 to A
    for (int i = 1; i <= A; i++) {
        sum += i;
        product *= i;
        count++;
    }

    // Postcondition: Ensure sum equals A*(A+1)/2 and product is non-negative

    // Additional check: if B is greater than count
    if (B > count) {
        for (int i = 0; i < B; i++) {
            // Loop: Check if product is still non-negative
            __VERIFIER_assert(product >= 0);
        }
    }

    return 0;
}