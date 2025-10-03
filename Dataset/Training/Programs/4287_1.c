#include <stdio.h>

// Function prototypes for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_verification.c", 3, "reach_error"); }
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

int main() {
    // Nondeterministic input
    int n = __VERIFIER_nondet_int();

    // Constraints for verification
    assume_abort_if_not(n >= 0 && n <= 12); // keeping it small to prevent overflow

    // Initializing variables
    int result = 1;
    int count = 1;

    // Loop to calculate factorial
    while (count <= n) {
        result = result * count;
        count++;
    }

    // Verifying the result with a condition
    // n! must be greater than or equal to 1 for n >= 0
    __VERIFIER_assert(result >= 1);

    // Print the result (only for manual testing, can be commented out)
    // printf("Factorial of %d is %d\n", n, result);

    return 0;
}