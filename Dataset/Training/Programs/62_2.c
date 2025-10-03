#include <stdlib.h>

// Function to simulate a verifier assumption, abort if condition is false
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to simulate a verifier assertion, abort if condition is false
void reach_error() {
    extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
    __assert_fail("0", "generated_program.c", 5, "reach_error");
}

// Verifier assertion function
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// External nondeterministic function
extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100); // Input within 1 to 100

    int sum = 0;
    int product = 1;
    int i = 1;

    // Loop to calculate the sum of odd numbers and product of even numbers up to n
    while (i <= n) {
        if (i % 2 == 0) {
            product *= i; // Multiply even numbers
        } else {
            sum += i; // Add odd numbers
        }
        i++;
    }

    // Assertion to verify that sum and product have expected properties
    __VERIFIER_assert(product > 0);

    return 0;
}