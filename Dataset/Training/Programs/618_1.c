#include <stdio.h>
#include <stdlib.h>

extern void reach_error(void);
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Simple computation to check if a sum of numbers is even or odd
int main() {
    int total = 0;
    int n = __VERIFIER_nondet_int();

    // Assuming n is a small positive number for some meaningful constraint
    assume_abort_if_not(n >= 1 && n <= 20);

    for (int i = 0; i < n; i++) {
        int num = __VERIFIER_nondet_int();
        // Assuming num is between 1 and 10
        assume_abort_if_not(num >= 1 && num <= 10);

        total += num;
    }

    // Check if the total sum is even
    if (total % 2 == 0) {
        printf("Sum is even: %d\n", total);
    } else {
        printf("Sum is odd: %d\n", total);
    }

    // Verify a condition about the total
    __VERIFIER_assert((total % 2 == 0) || (total % 2 == 1)); // Always true: A sum is either even or odd

    return 0;
}