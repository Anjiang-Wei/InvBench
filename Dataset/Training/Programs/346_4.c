// A program to compute the factorial of a number using an iterative approach

#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function to calculate factorial iteratively
int factorial(int n) {
    // Start with the base case where factorial(0) is 1
    int result = 1;
    int i = 1;
    while (i <= n) {
        result *= i;
        i++;
    }
    return result;
}

int main() {
    int num = __VERIFIER_nondet_int();

    // Only allow positive numbers for factorial computation
    if (num < 0) {
        return 0; // early exit for invalid input
    }

    int result = factorial(num);

    // Verify that factorial is correctly computed for small numbers
    if (num <= 5) {
        if (num == 0) {
        } else if (num == 1) {
        } else if (num == 2) {
        } else if (num == 3) {
            __VERIFIER_assert(result == 6);
        } else if (num == 4) {
        } else if (num == 5) {
        }
    }

    return 0;
}