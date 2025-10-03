#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 4, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n, i, total, threshold;

    n = __VERIFIER_nondet_int();
    if (!(n > 0 && n <= 1000)) {
        return 0;
    }

    threshold = __VERIFIER_nondet_int();
    if (threshold <= 0) {
        threshold = 500; // Default threshold
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 0;
    }

    // Initialize the array with nondeterministic values
    for (i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    total = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] > 0) {
            total += arr[i];
        }
    }

    // Check if the total is above or below a certain threshold
    if (total >= threshold) {
        printf("Total (%d) is above or equal to threshold (%d).\n", total, threshold);
    } else {
        printf("Total (%d) is below the threshold (%d).\n", total, threshold);
    }

    __VERIFIER_assert(total >= 0); // Ensuring that total cannot be negative
    free(arr);
    return 0;
}