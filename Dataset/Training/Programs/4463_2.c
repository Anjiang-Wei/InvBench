// Repeated subtraction integer division with verification
#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

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

extern unsigned int __VERIFIER_nondet_uint(void);

int main() {
    unsigned int dividend = __VERIFIER_nondet_uint();
    unsigned int divisor = __VERIFIER_nondet_uint();
    /* Restrict inputs to avoid non-termination and overflow */
    assume_abort_if_not(divisor > 0 && divisor <= 1000);
    assume_abort_if_not(dividend <= 100000);

    /* Initialize quotient and remainder */
    unsigned int quotient = 0;
    unsigned int remainder = dividend;

    /* Compute quotient = floor(dividend/divisor),
       remainder = dividend mod divisor */
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient++;
    }

    /* Check the division correctness */
    __VERIFIER_assert(dividend == quotient * divisor + remainder);

    return 0;
}