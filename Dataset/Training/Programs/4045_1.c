#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Function to calculate factorial
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n = 5; // Test with small numbers for simplicity
    int result = factorial(n);

    // Check if the result is equal to 120, which is 5!
    __VERIFIER_assert(result == 120);

    // Loop for additional computation
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += i;
    }

    // Verify the sum of first n natural numbers

    printf("Factorial of %d is %d and sum is %d\n", n, result, sum);

    return 0;
}