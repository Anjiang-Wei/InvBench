#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100);

    int factorial = 1;
    int i = 1;

    while (i <= n) {
        factorial *= i;
        i++;
    }

    __VERIFIER_assert(factorial >= 1); // Assert that factorial should be at least 1

    // Verify the factorial value for small n values
    if (n <= 5) {
        int expected_result;

        switch (n) {
        case 1:
            expected_result = 1;
            break;
        case 2:
            expected_result = 2;
            break;
        case 3:
            expected_result = 6;
            break;
        case 4:
            expected_result = 24;
            break;
        case 5:
            expected_result = 120;
            break;
        default:
            expected_result = 1; // Should not reach here for n <= 5
            break;
        }
    }

    return 0;
}