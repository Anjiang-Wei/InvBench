#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *);

void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }
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

extern int __VERIFIER_nondet_int(void);

#define SIZE 10

int main() {
    int array[SIZE];
    int target, sum, i, found = 0;

    // Initialize the array with non-deterministic values
    for (i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Choose a target sum non-deterministically
    target = __VERIFIER_nondet_int();

    // Ensure that the target is within a reasonable range
    assume_abort_if_not(target >= 0 && target <= 100);

    // Loop over the array to find any two elements that sum up to the target
    for (i = 0; i < SIZE; i++) {
        int j;
        for (j = i + 1; j < SIZE; j++) {
            if (array[i] + array[j] == target) {
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    // Verification that the outcome is binary: found or not found
    __VERIFIER_assert(found == 0 || found == 1);

    // Optionally print a message if an appropriate pair is found
    if (found) {
        printf("Found at least one pair of numbers that sum to %d\n", target);
    } else {
        printf("No pairs found that sum to %d\n", target);
    }

    return 0;
}