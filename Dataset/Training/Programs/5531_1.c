/*
  Program: Linear Search with Verification
  This program demonstrates a simple linear search in an array with accompanying assertions
  to verify the function implementation. It assumes that the key is always present
  in the array, and the array has a fixed size.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "linsearch.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

#define ARRAY_SIZE 10

// Linear search function
int linear_search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // should never reach here if key is present
}

int main() {
    int arr[ARRAY_SIZE], key;

    // Initialize an array with deterministic values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i * 2;
    }

    // Let's choose the key as a non-deterministic value from the array
    int index = __VERIFIER_nondet_int();
    assume_abort_if_not(index >= 0 && index < ARRAY_SIZE);
    key = arr[index];

    // Perform linear search
    int found_index = linear_search(arr, ARRAY_SIZE, key);

    // Assertions to verify correctness of the linear search
    __VERIFIER_assert(found_index >= 0 && found_index < ARRAY_SIZE);

    return 0;
}