#include <stdio.h>
#include <stdlib.h>

// Function declarations for verification tools
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "multiplication.c", 8, "reach_error"); }
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

// Function to multiply two integers using repeated addition
int multiply(int a, int b) {
    int result = 0;
    int i;

    // Ensure non-negative inputs
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    // Loop that performs repeated addition
    for (i = 0; i < b; i++) {
        result += a;
    }

    return result;
}

int main() {
    // Read inputs
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Assumptions to constrain inputs
    assume_abort_if_not(x >= 0 && x <= 10);
    assume_abort_if_not(y >= 0 && y <= 10);

    // Perform multiplication
    int product = multiply(x, y);

    // Assertions to verify the correctness of the multiplication
    __VERIFIER_assert(product == x * y);

    return 0;
}