/*
Arithmetic Progression Sum
computes the sum of the first `n` natural numbers and verifies it against the formula n*(n+1)/2
*/

#include <assert.h>
#include <stdio.h>

extern void abort(void);
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

int main() {
    int n, sum, i;
    n = 10; // Example fixed value, replace this with algebraic input if needed

    sum = 0;
    i = 1;

    while (i <= n) {
        sum = sum + i;
        i = i + 1;
    }

    // Verify the computed sum against the formula for the sum of first `n` natural numbers
    __VERIFIER_assert(sum == n * (n + 1) / 2);

    printf("Sum of first %d natural numbers is: %d\n", n, sum);
    return 0;
}