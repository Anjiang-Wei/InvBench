#include <assert.h>
#include <stdio.h>

extern void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (!(0 <= n && n <= 5)) {
        return 0; // Constraint to keep the problem within manageable size
    }

    // Compute factorial using recursion
    int fact = factorial(n);

    // Validate the factorial using an iterative method
    int i, fact_iterative = 1;
    for (i = 1; i <= n; ++i) {
        fact_iterative *= i;
    }

    // Assert that both methods yield the same result
    __VERIFIER_assert(fact == fact_iterative);

    // Print the result for confirmation
    printf("Factorial of %d is %d\n", n, fact);

    return 0;
}