#include <assert.h>
#include <stdbool.h>

// Function to indicate a verification failure
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int total_sum = 0;
    int current_factorial = 1;

    // Ensuring n is within a reasonable range for our calculations
    if (n < 0 || n > 10) {
        return 0;
    }

    for (int i = 0; i <= n; ++i) {
        current_factorial *= (i == 0 ? 1 : i); // Calculate factorial iteratively
        total_sum += current_factorial;
    }

    // Validating if the total sum of factorials is greater than zero
    __VERIFIER_assert(total_sum > 0);

    return 0;
}