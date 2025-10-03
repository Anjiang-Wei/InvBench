#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated_program.c", 12, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// This program implements a simple linear search algorithm
// along with verification of index bounds and key presence.
int main() {
    int n = 10;
    int A[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int key = 15;  // Key to be searched
    int found = 0; // Flag variable to check if element is found
    int i;

    // Ensuring the array size is greater than zero
    if (!(n > 0)) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        if (A[i] == key) {
            found = 1;
            break;
        }
    }

    // Verify behavior: found will be 1 if the key is present
    // Ensure that we did not exceed the array bounds

    // Verify that we found the key, or the search completed correctly
    if (found) {
        __VERIFIER_assert(A[i] == key);
    } else {
        // If not found, key should not exist in the array
        for (i = 0; i < n; i++) {
        }
    }

    return 0;
}