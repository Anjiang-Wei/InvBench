#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int compute(int x, int y) {
    if (x < 0 || y < 0) {
        return -1; // Invalid input
    }
    int result = 0;
    for (int i = 0; i < y; i++) {
        result += x; // Calculate x * y using repeated addition
    }
    return result;
}

int main(void) {
    int a = 7; // Test value for a
    int b = 5; // Test value for b

    int result = compute(a, b);

    // Verify the result
    __VERIFIER_assert(result == 35);

    // Loop to further manipulate the result
    int sum = 0;
    for (int i = 0; i < result; i++) {
        sum += i;
    }

    // Verify that the sum of first (result) natural numbers is correct

    printf("Computation successful: result = %d, sum = %d\n", result, sum);
    return 0;
}