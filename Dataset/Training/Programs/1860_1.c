#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
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
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int start, end;

    // Initialize start and end with non-deterministic values.
    start = __VERIFIER_nondet_int();
    end = __VERIFIER_nondet_int();

    // Assume conditions that make the program meaningful
    assume_abort_if_not(start >= 0 && start <= 10);
    assume_abort_if_not(end >= 10 && end <= 20);
    assume_abort_if_not(start < end);

    int current = start;
    int sum = 0;

    while (current <= end) {
        sum += current;
        current++;
    }

    // After the loop, we expect the sum to be equal to the sum of an arithmetic sequence.
    int expected_sum = (end * (end + 1)) / 2 - ((start - 1) * start) / 2;

    // Verify that the computed sum is equal to the expected sum.
    __VERIFIER_assert(sum == expected_sum);

    printf("Computed sum: %d, Expected sum: %d\n", sum, expected_sum);

    return 0;
}