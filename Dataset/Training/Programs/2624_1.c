/* A program to calculate the greatest common divisor (GCD) of two numbers
   using the Euclidean algorithm. */

#include <limits.h>

extern void abort(void);
#include <assert.h>
void reach_error() { assert(0); }
extern unsigned __VERIFIER_nondet_uint(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    unsigned int a, b;
    unsigned int temp;

    // Get two non-deterministic non-zero positive integers within a certain range
    a = __VERIFIER_nondet_uint();
    b = __VERIFIER_nondet_uint();

    assume_abort_if_not(a > 0 && a <= 1000);
    assume_abort_if_not(b > 0 && b <= 1000);

    // Using the Euclidean algorithm to find the GCD
    while (b != 0) {
        temp = b;
        b = a % b; // remainder of a divided by b
        a = temp;
    }

    // After the loop, 'a' should be the GCD
    __VERIFIER_assert(a > 0); // Verify that the result is always a positive integer
    return 0;
}