#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

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

int main() {
    int sum = 0;
    int limit = 1000; // This will be the upper limit of the sum
    int count = 0;
    int max_iterations = __VERIFIER_nondet_int();

    // Assume logical constraint on nondet input
    assume_abort_if_not(max_iterations > 0 && max_iterations <= limit);

    // Loop to accumulate sum until a certain limit or iterations
    while (count < max_iterations && sum < limit) {
        sum += count * 2; // Adding twice the current count to sum
        count++;

        // Verifying some invariants in the loop
    }

    // Final assertions after the loop
    __VERIFIER_assert(count <= max_iterations);

    // Check if the loop exited due to reaching the limit
    if (sum >= limit) {
    }

    printf("Final sum: %d\n", sum);
    printf("Iterations: %d\n", count);

    return 0;
}