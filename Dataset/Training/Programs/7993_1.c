#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }

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
    unsigned int x = 1;
    unsigned int factorial = 1;
    unsigned int n = 5; // Let's compute the factorial of 5

    while (x <= n) {
        factorial *= x;
        x++;
    }

    // Check if the computed factorial is correct (5! = 120)
    __VERIFIER_assert(factorial == 120);

    return 0;
}