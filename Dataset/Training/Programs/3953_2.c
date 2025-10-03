#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function to compute factorial using a loop
unsigned long factorial(int n) {
    if (n < 0) {
        return 0; // Factorial is not defined for negative numbers
    }
    unsigned long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to compute the sum of an array
int array_sum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int x = 5;
    int fact = factorial(x);

    // Verify that factorial of 5 is 120

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = array_sum(arr, size);

    // Verify that sum of the array is 15
    __VERIFIER_assert(sum == 15);

    // A loop for processing
    for (int i = 0; i < 10; ++i) {
        if (i < 5) {
            x += i;
        } else {
            x -= i;
        }
    }

    // Assert a condition after the loop

    return 0;
}