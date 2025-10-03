#include <stdio.h>
#include <stdlib.h>

// Example of linear search algorithm with verification constraints
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "linear_search.c", 9, "reach_error"); }
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
    return;
}

#define SIZE 10
int main() {
    int arr[SIZE];
    int target;
    int result = -1; // Position of target in the array, -1 if not found

    // Initialize the array with non-deterministic values
    for (int i = 0; i < SIZE; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }
    target = __VERIFIER_nondet_int();

    // Non-deterministically choose the target from within the array
    if (target < 0 || target >= SIZE) {
        target = arr[__VERIFIER_nondet_int() % SIZE];
    }

    // Linear search with constraint conditions
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == target) {
            result = i;
            break;
        }
    }

    // Verify the result is either correct position or -1 if target was not found
    if (result != -1) {
    } else {
        for (int i = 0; i < SIZE; i++) {
            __VERIFIER_assert(arr[i] != target);
        }
    }

    // Output result for verification
    printf("Target %d found at index: %d\n", target, result);

    return 0;
}