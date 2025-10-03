#include <stdio.h>
#include <stdlib.h>

// Function to simulate nondeterministic integer generation
extern int __VERIFIER_nondet_int(void);

// Function to handle verification errors
void reach_error() {
    printf("Verification failed.\n");
    abort();
}

// Custom assert function to verify conditions
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to simulate nondeterministic behavior in terminating the program
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, x, y;
    long long result = 0;

    // Initialize variables with nondeterministic values within specified constraints
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 10);

    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 10);

    x = a;
    y = b;

    // Implement a loop to emulate multiplication via repeated addition
    while (y > 0) {
        // Verification condition inside the loop
        __VERIFIER_assert(result + x * y == (long long)a * b);

        // Logic for multiplying x and y using repeated addition
        if (y % 2 == 1) {
            result += x;
            y--;
        }
        x *= 2;
        y /= 2;
    }

    // Final verification condition

    // Output the result of the computation
    printf("The product of %d and %d is %lld\n", a, b, result);

    return 0;
}