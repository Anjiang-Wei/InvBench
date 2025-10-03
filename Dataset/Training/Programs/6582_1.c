// A program demonstrating a simple computational pattern with verification assertions

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
}

int main() {
    int total_sum = 0;
    int expected_sum = 0;

    for (int i = 1; i <= 100; ++i) {
        total_sum += i; // Compute the sum of the first 100 natural numbers
        expected_sum += i;
        __VERIFIER_assert(total_sum == expected_sum); // check intermediate sum correctness
    }

    // Checking the final sum
    __VERIFIER_assert(total_sum == (100 * 101) / 2);

    printf("Total sum of first 100 natural numbers is: %d\n", total_sum);
    return 0;
}