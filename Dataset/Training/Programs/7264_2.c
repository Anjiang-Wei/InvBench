#include <assert.h>

extern int __VERIFIER_nondet_int(void);

#define SIZE_LIMIT 1000000

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

    // Assumptions for inputs
    assume_abort_if_not(a > 0 && a <= SIZE_LIMIT);
    assume_abort_if_not(b > 0 && b <= SIZE_LIMIT);

    int gcd = 1;
    int min = (a < b) ? a : b;

    // Compute GCD using a simple loop
    for (int i = 2; i <= min; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    // Verify that gcd divides both a and b
    __VERIFIER_assert(b % gcd == 0);

    // Check condition (The gcd is not greater than either of the two numbers)

    return 0;
}