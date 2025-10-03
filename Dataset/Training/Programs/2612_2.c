#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed.c", 3, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 100); // Assume a reasonable range for n

    int sum = 0;
    int prod = 1;

    for (int i = 1; i <= n; i++) {
        sum += i;
        prod *= i;

        // Assert that the sum of the first i natural numbers is consistent
    }

    // Check if the final product meets a known constraint
    if (n <= 5) {
        int expected_factorial;
        switch (n) {
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
            expected_factorial = -1;
        }
        __VERIFIER_assert(prod == expected_factorial);
    }

    return 0;
}