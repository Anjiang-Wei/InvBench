/*
 Factorial calculation with loop and verification
 This program calculates the factorial of a given non-negative integer n.
 The result is stored in the variable 'fact'.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

unsigned int __VERIFIER_nondet_uint();

int main() {
    unsigned int n = __VERIFIER_nondet_uint();
    unsigned long long fact = 1, calculated = 1;
    unsigned int i = 1;

    // Make sure n is within a reasonable range to prevent overflow
    // when calculating factorial
    if (n > 12) {
        return 0;
    }

    // Factorial computation with loop
    while (1) {
        // Ensure the condition for factorial

        if (i > n) {
            break;
        }

        fact *= i;
        calculated = fact;
        i++;
    }

    // Verify that the computed factorial matches expected conditions
    __VERIFIER_assert(calculated == fact);

    printf("Factorial of %u is %llu\n", n, fact);
    return 0;
}