#include <stdio.h>
#include <stdlib.h>

/* Function to simulate the non-deterministic input, replace with any specific input for testing */
int __VERIFIER_nondet_int(void) {
    return rand() % 100; // Random number between 0 and 99
}

/* Custom assert function to simulate verification failure */
void reach_error(void) {
    printf("Verification failed!\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

int main(void) {
    int a, b, n;
    long long sum = 0;
    long long product = 1;
    int limit = 10;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    if (n <= 0) {
        n = 1; // Ensure n is at least 1 to avoid products involving zero elements
    }

    if (b == 0) {
        b = 1; // Avoid division by zero in further computations
    }

    for (int i = 0; i < n && i < limit; ++i) {
        sum += a + i;
        product *= (b + i);
    }

    // Ensure that computations have resulted in valid logic by checking some basic properties
    __VERIFIER_assert(sum >= a);

    // Output the computed values for verification
    printf("Sum: %lld, Product: %lld\n", sum, product);

    return 0;
}