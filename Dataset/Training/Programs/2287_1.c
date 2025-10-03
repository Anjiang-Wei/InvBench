#include <stdio.h>
#include <stdlib.h>

// Custom assert function to trigger error
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "my_program.c", 5, "reach_error"); }
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

// Function to simulate computation with constraints
int compute(int a, int b) {
    int result = 0;
    int multiplier = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            result += a * multiplier;
        }
        multiplier *= 2;
        b /= 2;
    }

    return result;
}

int main() {
    int num1 = __VERIFIER_nondet_int();
    int num2 = __VERIFIER_nondet_int();

    // Constraint: num1 and num2 should be non-negative and within a specific range
    assume_abort_if_not(num1 >= 0 && num1 <= 50);
    assume_abort_if_not(num2 >= 0 && num2 <= 50);

    // Compute result based on the conditions
    int result = compute(num1, num2);

    // Assertion to verify the expected property
    __VERIFIER_assert(result >= 0);

    return 0;
}