#include <stdio.h>
#include <stdlib.h>

// Function declarations
extern void abort(void);
void reach_error() { abort(); }
extern void __VERIFIER_assert(int cond);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Utility function to calculate factorial
int factorial(int n) {
    int i, result = 1;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int x, n, result;
    x = rand() % 10 + 1; // Random number between 1 and 10
    n = rand() % 5 + 1;  // Random number between 1 and 5

    result = x;
    int sum = x;

    assume_abort_if_not(n >= 1); // Constraint: ensure n >= 1

    while (n > 0) {
        // Multiply `result` with `x` and add to `sum`
        result *= x;
        sum += result;
        n--;

        // Check constraint to ensure correctness of multiplication and sum

        if (n <= 0) {
            break;
        }
    }

    // Calculate factorial of x to include meaningful computation
    int fact_x = factorial(x);

    // Final assertion to check consistency
    __VERIFIER_assert(fact_x > 0);

    printf("Computation complete: x=%d, Factorial=%d\n", x, fact_x);

    return 0;
}