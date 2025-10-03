#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Function to simulate an error reaching point
void reach_error() {
    __assert_fail("0", "generated_program.c", 3, "reach_error");
}

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

// Custom assert function
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main() {
    int threshold = __VERIFIER_nondet_int();
    int limit = 20;
    int iterations = 0;

    if (threshold <= 0 || threshold >= limit) {
        return 0;
    }

    int *array = (int *)malloc(sizeof(int) * limit);
    if (!array) {
        reach_error();
        return 1;
    }

    // Initialize the array
    for (int i = 0; i < limit; i++) {
        array[i] = i * 2;
    }

    // Loop with a conditional constraint
    while (iterations < limit) {
        if (array[iterations] > threshold) {
            break;
        }
        iterations++;
    }

    // Check condition after loop
    __VERIFIER_assert(iterations == limit || array[iterations] > threshold);

    // Print the result
    printf("Iterations completed: %d\n", iterations);

    free(array);
    return 0;
}