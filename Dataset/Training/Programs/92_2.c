/*
  Fibonacci sequence generator with assertions to check the sequence property
*/
#include <stdio.h>
#include <stdlib.h>

// Verification setup
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

#define MAX_FIBONACCI_TERMS 10

int main() {
    long long fibonacci[MAX_FIBONACCI_TERMS];
    int terms;

    // Determine number of Fibonacci terms
    terms = __VERIFIER_nondet_int();
    assume_abort_if_not(terms >= 2 && terms <= MAX_FIBONACCI_TERMS);

    // Initial condition for the Fibonacci sequence
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    // Compute and verify Fibonacci sequence properties
    for (int i = 2; i < terms; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        // Check the property of the sequence at each step
    }

    // Final assertion to verify the sequence property holds for the last calculated term
    if (terms >= 3) {
        __VERIFIER_assert(fibonacci[terms - 1] == fibonacci[terms - 2] + fibonacci[terms - 3]);
    }

    // Print the generated Fibonacci sequence
    printf("Fibonacci sequence up to %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%lld ", fibonacci[i]);
    }
    printf("\n");

    return 0;
}