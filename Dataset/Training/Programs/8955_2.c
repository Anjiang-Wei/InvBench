#include <stdio.h>
#include <stdlib.h>

void abort(void);
void reach_error() { abort(); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n, x, y, sum;
    n = __VERIFIER_nondet_int();

    // Constraint for the verifier
    if (n < 0 || n > 1000) {
        return 0;
    }

    sum = 0;
    x = 1;
    y = n;

    // Loop performing a simple arithmetic series sum
    while (x <= n) {
        sum += x;
        y--; // Dummy operation to introduce an extra variable dependency
    }

    // Final assertion for the entire series
    __VERIFIER_assert(sum == ((n * (n + 1)) / 2));

    printf("Sum of the first %d natural numbers is: %d\n", n, sum);
    return 0;
}