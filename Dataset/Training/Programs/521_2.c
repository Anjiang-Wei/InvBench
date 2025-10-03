#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "linear_search.c", 8, "reach_error"); }
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

int linear_search(int arr[], int size, int target) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            found = 1;
            break;
        }
    }
    return found;
}

int main() {
    int size = 10;
    int arr[size];
    int target, i;

    for (i = 0; i < size; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    target = __VERIFIER_nondet_int();

    // Assume target is within a certain range
    assume_abort_if_not(target >= 0 && target <= 100);

    // Call the linear search function
    int result = linear_search(arr, size, target);

    // Verify some properties
    if (result == 1) {
        int found = 0;
        for (i = 0; i < size; i++) {
            if (arr[i] == target) {
                found = 1;
                break;
            }
        }
        __VERIFIER_assert(found == 1);
    }

    return 0;
}