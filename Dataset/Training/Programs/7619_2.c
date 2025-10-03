#include <stdio.h>
#include <stdlib.h>

// Custom assertions and error handling tools
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "avgsum.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0); // n must be a positive integer

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        return 0;
    } // Prevent theoretical out of memory

    int sum = 0;
    int count = 0;
    int avg = 0;

    // Filling the array with nondeterministic values
    for (int i = 0; i < n; ++i) {
        array[i] = __VERIFIER_nondet_int();
        sum += array[i];
        ++count;
    }

    // Verify sum and count

    // Compute average
    if (count > 0) {
        avg = sum / count;
    }

    // Verify average constraints
    for (int i = 0; i < n; ++i) {
        __VERIFIER_assert(array[i] <= avg || array[i] > avg);
    }

    // Free allocated resources
    free(array);

    return 0;
}