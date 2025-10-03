/*
 Simple Linear Search with Verification
 Performs a linear search on an array and ensures the element is either found or not present
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "linear_search.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

#define SIZE 10

int main() {
    int arr[SIZE];
    int i, target, found = 0;

    // Initialize array with non-deterministic values
    for (i = 0; i < SIZE; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    // Get a target value to search for
    target = __VERIFIER_nondet_int();

    // Linear search algorithm
    for (i = 0; i < SIZE; i++) {
        if (arr[i] == target) {
            found = 1;
            break;
        }
    }

    // Verification: If found, arr[i] should be equal to target
    if (found) {
        __VERIFIER_assert(arr[i] == target);
    } else {
        // Check the element should not be in array
        for (i = 0; i < SIZE; i++) {
        }
    }

    return 0;
}