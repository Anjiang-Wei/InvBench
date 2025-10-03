#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }
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

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int size;
} IntArray;

void initialize_array(IntArray *arr) {
    arr->size = 0;
    while (__VERIFIER_nondet_int() && arr->size < MAX_SIZE) {
        arr->arr[arr->size] = __VERIFIER_nondet_int();
        arr->size++;
    }
}

int sum_array(IntArray *arr) {
    int sum = 0;
    for (int i = 0; i < arr->size; i++) {
        sum += arr->arr[i];
    }
    return sum;
}

int main() {
    IntArray array1, array2;
    initialize_array(&array1);
    initialize_array(&array2);

    __VERIFIER_assert(array2.size <= MAX_SIZE);

    int sum1 = sum_array(&array1);
    int sum2 = sum_array(&array2);

    // Assuming some constraints for verification

    // Calculate the difference
    int difference = sum1 - sum2;
    if (difference < 0) {
        difference = -difference;
    }

    return 0;
}