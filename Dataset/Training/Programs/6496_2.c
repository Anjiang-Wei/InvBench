#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { abort(); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

#define ARRAY_SIZE 10

int sum_of_elements(int arr[], int size) {
    int sum = 0, i;
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[ARRAY_SIZE];
    int sum = 0;
    int k = __VERIFIER_nondet_int();

    assume_abort_if_not(k >= 0 && k <= 10);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= -10 && arr[i] <= 10);
        printf("Element %d: %d\n", i, arr[i]);
    }

    sum = sum_of_elements(arr, ARRAY_SIZE);

    printf("Sum of elements: %d\n", sum);

    // Check the basic constraint condition
    if (k == 0) {
    } else if (k == ARRAY_SIZE) {
        __VERIFIER_assert(sum == sum_of_elements(arr, ARRAY_SIZE));
    }

    return 0;
}