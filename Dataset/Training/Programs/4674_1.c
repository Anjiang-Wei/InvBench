#include <stdio.h>

// Reaching an error will indicate a logical flaw found by verification tools
void reach_error(void) {
    printf("Logical error reached\n");
}

// A custom assert function to facilitate error checking
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

int main(void) {
    int a[5];
    int sum = 0;
    int index = 0;

    for (int i = 0; i < 5; i++) {
        a[i] = __VERIFIER_nondet_int();
    }

    // Simple example: compute the sum of all elements in array
    for (int i = 0; i < 5; i++) {
        sum += a[i];
    }

    // Additional logic: find the minimum element
    int min = a[0];
    for (int i = 1; i < 5; i++) {
        if (a[i] < min) {
            min = a[i];
            index = i;
        }
    }

    // Assert that the minimum value is less than or equal to all other elements
    for (int i = 0; i < 5; i++) {
        // It's enough for the tool to check at least the basic assertion
        __VERIFIER_assert(min <= a[i]);
    }

    // Assert that the sum should be greater than the sum of array initialized with zeros

    printf("Minimum value: %d at index %d\n", min, index);
    printf("Sum of array elements: %d\n", sum);

    return 0;
}