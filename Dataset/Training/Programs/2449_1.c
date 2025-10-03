#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_error() __attribute__((__noreturn__));
void reach_error(void) { __VERIFIER_error(); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int counter = 0;

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0) {
        return 0; // Constraint: n must be non-negative
    }

    int a = 0, b = 1;
    int index = 0;
    int temp;

    // This loop calculates Fibonacci numbers
    while (index < n && counter++ < 50) {
        __VERIFIER_assert(a >= 0 && b >= 0); // Keep track of non-negative numbers

        // Fibonacci progression step
        temp = a + b;
        a = b;
        b = temp;

        index++;
    }

    // Property check: Fibonacci numbers should remain non-negative

    printf("Fibonacci calculation completed.\n");
    return 0;
}