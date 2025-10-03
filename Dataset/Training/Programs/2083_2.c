// A C program suitable for verification by automated tools

#include <stdio.h>
#include <stdlib.h>

// Function declarations for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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

// A function that performs some calculations and ensures constraints
void perform_calculations(int n) {
    int i = 0;
    int sum = 0;
    int product = 1;

    assume_abort_if_not(n >= 1 && n <= 100);

    while (i < n) {
        sum = sum + i;
        product = product * (i + 1);

        // Verify constraints
    }

    // Final check to ensure program logic holds
    __VERIFIER_assert(sum == (n * (n - 1)) / 2);
}

int main() {
    int input = __VERIFIER_nondet_int();

    // Ensure input is within a reasonable range
    assume_abort_if_not(input > 0 && input <= 10);

    // Perform calculations with the given input
    perform_calculations(input);

    return 0;
}