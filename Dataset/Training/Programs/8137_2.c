#include <stdio.h>

// Function declarations
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "my-program.c", 5, "reach_error"); }
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

// Function to calculate factorial iteratively
int factorial(int n) {
    int i;
    int fact = 1;

    for (i = 1; i <= n; ++i) {
        fact *= i;
        // Ensure intermediate factorial value does not exceed certain limit for tool verification
    }

    return fact;
}

int main() {
    int num = __VERIFIER_nondet_int();
    assume_abort_if_not(num >= 0 && num <= 10); // Valid range for factorial computation
    int result = factorial(num);

    printf("Factorial of %d is %d\n", num, result);

    // Check post-condition
    __VERIFIER_assert(result > 0);

    return 0;
}