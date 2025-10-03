#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n, i, factorial, sum_of_squares;

    n = __VERIFIER_nondet_int();
    if (!(n >= 1)) {
        return 0; // Assume n is a positive integer
    }

    factorial = 1;
    sum_of_squares = 0;

    for (i = 1; i <= n; i++) {
        factorial *= i;
        sum_of_squares += i * i;
        if (factorial <= 0) {
            break; // Handle potential integer overflow
        }
    }

    printf("Factorial of %d is %d\n", n, factorial);
    printf("Sum of squares up to %d is %d\n", n, sum_of_squares);

    __VERIFIER_assert(factorial > 0);       // Assert that factorial should be positive if no overflow
    __VERIFIER_assert(sum_of_squares >= n); // Assert some basic property of sum_of_squares

    return 0;
}