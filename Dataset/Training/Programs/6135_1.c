#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    unsigned int x = 1;
    unsigned int factorial = 1;
    unsigned int target = 5;

    // Calculate factorial of target
    while (x <= target) {
        factorial *= x;
        x++;
    }

    // Verify that the factorial of 5 is 120
    __VERIFIER_assert(factorial == 120);

    printf("Factorial of %u is %u\n", target, factorial);

    return 0;
}