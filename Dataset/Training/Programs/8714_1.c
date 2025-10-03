#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main(void) {
    int mainArray[10];
    int sum = 0;
    int i = 0;
    int n = __VERIFIER_nondet_int(); // This can represent the number of times the loop will execute

    // Initialize the array with values
    for (int j = 0; j < 10; ++j) {
        mainArray[j] = __VERIFIER_nondet_int();
    }

    // Ensure n is a valid number less than or equal to the length of the mainArray
    if (n < 0 || n > 10) {
        return 0;
    }

    // Calculate the sum of n elements of the array
    while (i < n) {
        sum += mainArray[i];
        ++i;
    }

    // Check if the sum condition holds after the loop
    __VERIFIER_assert(sum >= 0 || n <= 10); // This is just a sample condition, replace with meaningful logic

    return 0;
}