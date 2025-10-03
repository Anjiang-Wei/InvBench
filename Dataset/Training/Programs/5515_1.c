#include <stdio.h>
#include <stdlib.h>

// Function declarations for error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_program.c", 8, "reach_error"); }

// A function to simulate assumptions, aborting if the condition is false
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// A function to simulate assertions, reaching an error state and aborting if the condition is false
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function to simulate an external integer input
extern int __VERIFIER_nondet_int(void);

int main() {
    // Define the size of array and counter variables
    int SIZE, i, count_even = 0, count_odd = 0;
    long long sum_even = 0, sum_odd = 0;

    // Get a nondeterministic integer for SIZE
    SIZE = __VERIFIER_nondet_int();

    // Assume SIZE is a reasonable positive number
    assume_abort_if_not(SIZE > 0 && SIZE <= 1000000);

    // Dynamically allocate memory for the array
    int *array = (int *)malloc(SIZE * sizeof(int));

    // Fill the array with values from a nondeterministic source
    for (i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int() % 100; // Values are restricted to 0-99
    }

    // Traverse the array and separate the sums of even and odd numbers
    for (i = 0; i < SIZE; i++) {
        if (array[i] % 2 == 0) {
            sum_even += array[i];
            count_even++;
        } else {
            sum_odd += array[i];
            count_odd++;
        }
    }

    // Assert that the number of even and odd numbers sums up to SIZE
    __VERIFIER_assert((count_even + count_odd) == SIZE);

    // Free the dynamically allocated memory
    free(array);

    return 0;
}