#include <stdio.h>
#include <stdlib.h>

// Function to simulate a failure if a condition is violated
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 5, "reach_error"); }

// Assert function maintaining logic integrity of assertions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Helper function to verify non-deterministic integer values
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Main logic function
int main() {
    int target, x, y;
    long long product = 1;

    // Non-deterministic value assignment
    target = __VERIFIER_nondet_int();
    assume_abort_if_not(target > 1 && target < 1000);

    x = 1;
    y = 0;

    // Loop to reach the target product through incremental sums
    while (y < target) {
        y += x;
        product *= 2;

        if (y >= target) {
            break; // Break condition when target is met or exceeded
        }

        // Increment x to create variability in the loop
        x += 3;

        // Assert that ensures that our product and y are synchronized
    }

    printf("Final values: x=%d, y=%d, product=%lld\n", x, y, product);

    // Final assertion to check that our logic holds at the end of the loop
    __VERIFIER_assert(y >= target && product > 0);

    return 0;
}