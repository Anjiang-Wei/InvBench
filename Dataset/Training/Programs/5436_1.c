#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n, sum = 0, current = 0;

    // Get a nondeterministic integer n
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 1000); // assume a reasonable range for verification

    // Dynamic memory allocation for simulation of an array
    int *array = (int *)malloc(sizeof(int) * n);
    if (array == NULL) {
        return 0; // exit if memory isn't allocated
    }

    // Initialize array with some values computed based on an incremental pattern
    for (int i = 0; i < n; i++) {
        array[i] = i * i; // assigning square of the index
    }

    // Calculating sum of elements in the array with a complex condition inside the loop
    while (current < n) {
        sum += array[current];
        // Apply a constraint that the sum is even
        if (sum % 2 != 0) {
            sum -= array[current]; // undo the addition if it makes the sum odd
        }
        current++;
    }

    free(array);                     // Free allocated memory
    __VERIFIER_assert(sum % 2 == 0); // Assert that the final sum is even as per our logic

    return 0;
}