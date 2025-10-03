#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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

// Program Description:
// This program calculates the factorial of a given integer n (0 <= n <= 5),
// and ensures the calculated factorial value matches a known result using assertions.

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 5); // Limiting n to small numbers for factorial verification

    int factorial = 1;

    // Calculate the factorial of n
    for (int i = 2; i <= n; ++i) {
        factorial *= i;
    }

    // Known factorial values for numbers 0 to 5
    int expected_factorial;
    switch (n) {
    case 0:
        expected_factorial = 1;
        break;
    case 1:
        expected_factorial = 1;
        break;
    case 2:
        expected_factorial = 2;
        break;
    case 3:
        expected_factorial = 6;
        break;
    case 4:
        expected_factorial = 24;
        break;
    case 5:
        expected_factorial = 120;
        break;
    default:
        expected_factorial = -1; // Should never reach here
    }

    // Verify calculated factorial matches the expected factorial
    __VERIFIER_assert(factorial == expected_factorial);

    return 0;
}