#include <stdio.h>
#include <stdlib.h>

// Function declarations
extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);

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

int main() {
    int n, i;
    long long factorial = 1, sum = 0, c = 0;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Restricting n to a reasonable range

    // Calculate factorial of n
    i = 1;
    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Compute sum of squares up to n
    i = 1;
    while (i <= n) {
        sum += i * i;
        i++;
    }

    // Verification logic
    // The following conditions should hold true.
    __VERIFIER_assert(sum >= 0);

    // Make sure that calculation logic is processed correctly
    printf("Factorial of %d is %lld\n", n, factorial);
    printf("Sum of squares up to %d is %lld\n", n, sum);

    return 0;
}