#include <stdio.h>
#include <stdlib.h>

// This program is intended to be analyzed and verified by automated verification tools.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int n, i, result;

    n = __VERIFIER_nondet_int();

    // Assume n is a positive integer
    if (n <= 0) {
        return 1;
    }

    result = 1; // Start with a neutral element for multiplication

    for (i = 1; i <= n; i++) {
        result *= i;

        // Ensure no overflow in factorial calculation
        __VERIFIER_assert(result > 0);
    }

    // Verify the factorial computation (n! > 0 for positive n)

    printf("The factorial of %d is %d\n", n, result);
    return 0;
}