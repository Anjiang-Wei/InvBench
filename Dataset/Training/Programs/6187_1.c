#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_example.c", 3, "reach_error"); }

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

// Function to calculate factorial
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to perform some operations on an array
int *manipulate_array(int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        array[i] = array[i] * 2;
    }
    return array;
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0 || N > 10) {
        return 0; // Ensuring reasonable size for demonstration
    }

    // Allocate array memory
    int *array = (int *)malloc(N * sizeof(int));
    if (!array) {
        abort();
    }

    // Populate the array with values
    int i;
    for (i = 0; i < N; i++) {
        array[i] = i + 1;
    }

    // Calculate factorial of N
    int factorial_of_N = factorial(N);

    // Manipulate the array
    manipulate_array(array, N);

    // Verify that the first element of the array is double its expected original value
    __VERIFIER_assert(array[0] == 2 * 1);

    // Check if the sum of the array should lead to a specific condition
    int sum = 0;
    for (i = 0; i < N; i++) {
        sum += array[i];
    }

    // Condition to verify: The sum of the manipulated array should be equal to `factorial_of_N`

    free(array);
    return 0;
}