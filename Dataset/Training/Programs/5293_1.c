// A C program using patterns and structures learned from the provided examples.
// The program is designed to perform computations under certain constraints and is suitable for verification.

#include <assert.h>
#include <stdbool.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "new_example.c", 5, "reach_error");
}

extern int __VERIFIER_nondet_int();

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    int sum = 0;
    int count = 0;
    int threshold;

    threshold = __VERIFIER_nondet_int();
    // Assume threshold is within a reasonable range
    assume_abort_if_not(threshold > 0 && threshold < 1000);

    while (count < threshold) {
        // Increment sum and count
        sum += count;
        count++;

        // Check specific property inside the loop
        __VERIFIER_assert(sum >= (count * (count - 1)) / 2);
    }

    // Check that the final sum is correct

    return 0;
}