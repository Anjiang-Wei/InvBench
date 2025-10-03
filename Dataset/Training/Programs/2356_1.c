#include <assert.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Precondition: Initialize conditions such that b is positive
    if (!(b > 0)) {
        return 0;
    }

    // Variables for the loop logic
    int quotient = 0;
    int remainder = a;

    // Loop until remainder is less than b
    while (remainder >= b) {
        int temp = b;
        int multiple = 1;

        // Double temp and multiple until temp surpasses remainder
        while (remainder >= (temp << 1)) {
            temp = temp << 1;
            multiple = multiple << 1;
        }

        // Subtract current temp from remainder
        remainder -= temp;
        quotient += multiple;
    }

    // Post-condition check
    __VERIFIER_assert(a == quotient * b + remainder);

    return 0;
}