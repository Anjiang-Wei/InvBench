#include <assert.h>
void reach_error(void) { assert(0); }

// External functions simulating nondeterministic behavior
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        // Simulate abrupt termination of the program if the condition is not met
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int dividend = __VERIFIER_nondet_int();
    int divisor = __VERIFIER_nondet_int();
    assume_abort_if_not(divisor != 0); // Division by zero check

    int quotient = 0;
    int remainder = dividend;

    // Simulate division with a loop (repeated subtraction)
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient++;
    }

    // Verification conditions
    // Ensure that: dividend = divisor * quotient + remainder
    // and 0 <= remainder < divisor
    __VERIFIER_assert(dividend == divisor * quotient + remainder);

    return 0;
}