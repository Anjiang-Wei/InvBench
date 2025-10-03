#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int __VERIFIER_nondet_int() {
    return rand(); // Random integer for simulation purpose
}

int main() {
    int size = 10;
    int a[size];
    int sum = 0, product = 1;
    int i;

    // Initialize and process the array with a loop
    for (i = 0; i < size; i++) {
        a[i] = __VERIFIER_nondet_int() % 100; // Get random integers between 0 and 99

        if (a[i] % 2 == 0) {
            sum += a[i];
        } else {
            product *= a[i];
        }
    }

    // Verification conditions
    __VERIFIER_assert(product != 0); // Assumption: no integer overflow

    // Output results
    printf("Sum of even numbers: %d\n", sum);
    printf("Product of odd numbers: %d\n", product);

    return 0;
}