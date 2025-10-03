#include <stdio.h>
#include <stdlib.h>

// External verification functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
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
    int a = 0; // Start from zero
    int b = 0; // Another counter
    int limit = __VERIFIER_nondet_int();

    // Ensure the limit is positive and within a certain bound
    assume_abort_if_not(limit > 0 && limit <= 1000);

    while (a < limit) {
        if (a % 3 == 0) {
            b += 2;
        } else if (a % 4 == 0) {
            b += 3;
        } else if (a % 5 == 0) {
            b += 5;
        } else {
            b++;
        }
        a++;
    }

    // Verifier assertion to check basic arithmetic based on loop logic
    // Ensures that after the loop, 'b' is non-negative and not exceeding a specific threshold
    __VERIFIER_assert(b >= 0 && b <= 10 * limit);

    // Using printf for additional output; irrelevant to verification but useful for manual checks
    printf("Final values: a = %d, b = %d\n", a, b);

    return 0;
}