#include <stdio.h>
#include <stdlib.h>

// Assertion mechanism similar to the examples
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_example.c", 6, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Program demonstrating compression-like logic through transformations
int main(void) {
    int input, target_sum;
    int accumulator = 0;
    int multiplier = 1;
    int steps = 0;
    const int LIMIT = 15; // step limit

    // Simulate nondeterministic input
    input = rand() % 100;
    target_sum = rand() % 200;

    // Ensure input meets assumptions
    if (input < 1 || target_sum < 50) {
        return 0;
    }

    while (steps++ < LIMIT) {
        if (accumulator >= target_sum) {
            break;
        }

        accumulator += input;
        input += multiplier;
        multiplier *= 2;
    }

    // Condition verifying the sum is sufficient
    __VERIFIER_assert(accumulator >= target_sum);

    printf("Final Accumulator: %d\n", accumulator);
    return 0;
}