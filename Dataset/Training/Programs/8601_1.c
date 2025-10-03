#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
 Program to simulate a bounded linear search within an array
 where we discover if a nondeterministically chosen value 'key'
 exists in the array 'arr'. If 'key' is found or end of array is
 reached, the loop terminates.
*/
#define ARRAY_SIZE 10

int main() {
    int key = __VERIFIER_nondet_int();
    int arr[ARRAY_SIZE];

    // Nondeterministically initialize the array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    int found = 0;
    int i = 0;

    // Perform a bounded linear search
    while (i < ARRAY_SIZE && !found) {
        if (arr[i] == key) {
            found = 1;
        }
        i++;
    }

    // Since the loop is supposed to identify the existence of 'key' in 'arr',
    // after the loop 'found' should be 1 if 'key' was in the array;
    if (found) {
        __VERIFIER_assert(arr[i - 1] == key); // If found, the last element checked should be 'key'
    } else {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            __VERIFIER_assert(arr[j] != key); // If not found, 'key' shouldn't be in the array
        }
    }

    return 0;
}