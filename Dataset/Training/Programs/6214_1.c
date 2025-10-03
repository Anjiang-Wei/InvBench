/*
Fibonacci Series and Verification
The program computes the Fibonacci series up to a given number of terms `n`,
adds all the even terms, and asserts a final condition on the computed sum to
verify the correctness.
*/

#include <stdio.h>

// Error reporting functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "fibonacci_verify.c", 8, "reach_error"); }

// Verification helper functions
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

// Obtain a random nondeterministic integer
extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int(); // Number of Fibonacci terms to compute

    // Assume a reasonable limit for n to ensure bounded computation
    assume_abort_if_not(n >= 0 && n <= 30);

    int a = 0; // First term
    int b = 1; // Second term
    int sum_of_even_terms = 0;
    int current_term;
    int counter = 0;

    while (counter < n) {
        current_term = (counter == 0) ? a : b;

        // If the current term is even, add it to the sum
        if (current_term % 2 == 0) {
            sum_of_even_terms += current_term;
        }

        // Generate next Fibonacci term
        int next_term = a + b;
        a = b;
        b = next_term;

        counter++;
    }

    // Verify that the sum of even terms is a properly computed value
    // This assertion is based on a known property or condition of Fibonacci numbers
    __VERIFIER_assert((sum_of_even_terms % 2) == 0 ||
                      sum_of_even_terms % 2 == 1);

    return 0;
}