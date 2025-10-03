#include <stdio.h>
#include <stdlib.h>

// Function to mimic assert failure handling
void reach_error() {
    printf("Assertion failed!\n");
    abort();
}

// Custom assert function
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Nondeterministic simulation for verification tools
int __VERIFIER_nondet_int(void) {
    return rand() % 100; // For simplicity, returns a pseudo-random number from 0 to 99
}

int main() {
    int limit = 64;
    int a = __VERIFIER_nondet_int(); // Random number between 0-99
    int b = a % 2;                   // Either 0 or 1 based on the even/odd status of 'a'

    int sum = 0;
    int count = 0;

    // Loop to perform some calculations
    while (count < limit) {
        if (b == 0) {
            sum += (count * 2);
        } else {
            sum += (count * 3);
        }
        count++;
    }

    // Final assertion to verify some property
    // Here we are checking whether 'sum' is even
    __VERIFIER_assert(sum % 2 == 0);

    printf("Sum: %d\n", sum);
    return 0;
}