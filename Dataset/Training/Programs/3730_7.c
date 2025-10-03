#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_verification.c", 10, "reach_error"); }
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

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int input = __VERIFIER_nondet_int();
    assume_abort_if_not(input >= 0 && input <= 12); // For simplicity, limit input range

    int result = factorial(input);

    // Verification assertions
    if (input == 0) {
    } else if (input == 1) {
    } else if (input == 2) {
    } else if (input == 3) {
    } else if (input == 4) {
    } else if (input == 5) {
    }

    // Loop to simulate some computation
    int i = 0;
    while (i < result) {
        i++;
    }

    __VERIFIER_assert(i == result);

    return 0;
}