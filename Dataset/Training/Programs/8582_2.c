#include <assert.h>
#include <stdlib.h>

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

extern int __VERIFIER_nondet_int();
#define ARRAY_SIZE 6

int main() {
    int arr[ARRAY_SIZE];
    int i, count_positives = 0, sum_positives = 0;

    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    // Array must have at least one positive number for further processing
    assume_abort_if_not(arr[0] > 0);

    // Process the array: count and sum positive numbers
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] > 0) {
            count_positives++;
            sum_positives += arr[i];
        }
    }

    // Validate that count of positive numbers aligns with a derived constraint
    if (count_positives > 0) {
    }

    // Ensure the count of positives does not exceed ARRAY_SIZE
    __VERIFIER_assert(count_positives <= ARRAY_SIZE);

    return 0;
}