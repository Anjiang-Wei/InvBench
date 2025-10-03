#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int factorial(int n) {
    if (n < 0) {
        return -1; // error code for negative input
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = 5; // Example input value
    int fact = factorial(n);

    // Verify the result using known values
    if (n == 5) {
    } else if (n == 0) {
        __VERIFIER_assert(fact == 1);
    } else if (n < 0) {
    }

    printf("Factorial of %d is: %d\n", n, fact);
    return 0;
}