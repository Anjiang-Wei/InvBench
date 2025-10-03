#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} IntArray;

// Function to add an element to the array
void add_element(IntArray *arr, int element) {
    if (arr->size < MAX_SIZE) {
        arr->data[arr->size++] = element;
    }
}

// Function to calculate the sum of the array
int calculate_sum(IntArray *arr) {
    int sum = 0;
    for (int i = 0; i < arr->size; i++) {
        sum += arr->data[i];
    }
    return sum;
}

int main() {
    IntArray array;
    array.size = 0;

    // Nondeterministically add elements to the array
    while (__VERIFIER_nondet_int() && array.size < MAX_SIZE) {
        int elem = __VERIFIER_nondet_int();
        add_element(&array, elem);
    }

    // Check the invariant that array size should not exceed MAX_SIZE
    __VERIFIER_assert(array.size <= MAX_SIZE);

    // Calculate the sum of the array elements
    int sum = calculate_sum(&array);

    // Validate the sum calculation with an invariant
    int expected_sum = 0;
    for (int i = 0; i < array.size; i++) {
        expected_sum += array.data[i];
    }

    // Ensure that the sum is non-negative

    printf("Array size: %d\n", array.size);
    printf("Sum of elements: %d\n", sum);

    return 0;
}