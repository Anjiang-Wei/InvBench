#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    unsigned int a = 0;
    unsigned int b = 1;
    unsigned int k = 10;
    unsigned int sum = 0;

    // Loop iterates while a is less than k
    while (a < k) {
        a++;
        b *= 2;
        sum += b;

        // Check if sum is an even number
    }

    // Final check to ensure the loop transformed the variables as expected
    __VERIFIER_assert(a == k);
    return 0;
}