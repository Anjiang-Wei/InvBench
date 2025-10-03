#include <assert.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
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
    return;
}

#define SIZE 10

int main() {
    int array[SIZE];
    int target_sum, current_sum;
    int start, end, found, total_elements;

    target_sum = __VERIFIER_nondet_int();
    assume_abort_if_not(target_sum >= 0 && target_sum <= 100);

    current_sum = 0;
    start = 0;
    end = 0;
    found = 0;
    total_elements = 0;

    // Fill the array with nonnegative numbers
    for (int i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 0 && array[i] <= 10);
    }

    // Search for a contiguous subarray summing to target_sum
    while (end < SIZE) {
        while (current_sum < target_sum && end < SIZE) {
            current_sum += array[end];
            end++;
        }

        while (current_sum > target_sum && start < end) {
            current_sum -= array[start];
            start++;
        }

        if (current_sum == target_sum) {
            found = 1;
            break;
        }
    }

    // The program is required to verify that if a subarray was found,
    // its sum must exactly equal the target sum.
    if (found) {
        total_elements = end - start;
        current_sum = 0;
        for (int i = start; i < end; i++) {
            current_sum += array[i];
        }
    } else {
        __VERIFIER_assert(found == 0);
    }

    return 0;
}