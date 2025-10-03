#include <stdio.h>

// External functions for non-determinism and verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "my_example.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
        abort();
    }
    return;
}

// Program with a loop and some meaningful logic
int main() {
    int n, limit, sum, i;

    // Use non-determinism to choose a size
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0); // Ensure it's positive

    // Set limit as twice of n
    limit = 2 * n;
    sum = 0;
    i = 1;

    // Compute the sum of integers from 1 to limit
    // Ensure that each step is less than three fourths of limit
    while (i <= limit) {
        if (sum + i < (3 * limit) / 4) {
            sum += i;
            i++;
        } else {
            break;
        }
    }

    // Verify that the sum is less than the full expected sum
    __VERIFIER_assert(sum < (limit * (limit + 1)) / 2);

    printf("Final sum: %d\n", sum);
    return 0;
}