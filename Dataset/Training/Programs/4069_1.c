#include <assert.h>
#include <stdlib.h>

// External function prototypes to simulate nondeterministic inputs
extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Function to handle error condition
void reach_error() {
    __assert_fail("0", "new_program.c", 6, "reach_error");
}

// Function to perform assertion and aborts if condition is false
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function that assumes the condition is true or aborts
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int(); // Non-deterministic input for a
    int b = __VERIFIER_nondet_int(); // Non-deterministic input for b

    // Assumptions/constraints about inputs
    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    int gcd = 1;                    // Initialize gcd
    int minValue = (a < b) ? a : b; // Determine minimum of a and b

    // Compute greatest common divisor (GCD) using an iterative loop
    for (int i = 1; i <= minValue; ++i) {
        if (a % i == 0 && b % i == 0) {
            gcd = i; // Update gcd if both a and b are divisible by i
        }
    }

    // Verify the computed GCD
    __VERIFIER_assert((a % gcd == 0) && (b % gcd == 0)); // Assert both a and b are divisible by gcd
    __VERIFIER_assert(gcd <= a && gcd <= b);             // Assert gcd is less than or equal to both

    return 0;
}