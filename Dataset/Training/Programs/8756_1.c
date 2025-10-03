#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// This program calculates the sum of consecutive squares and verifies a relationship
// between the sum, the last element squared, and the individual element.
int main() {
    int n = __VERIFIER_nondet_int();        // Number of terms
    assume_abort_if_not(n >= 1 && n <= 50); // Constraint: 1 <= n <= 50

    int sum_of_squares = 0;
    int last_square = 0;
    int i = 1;
    int counter = 0;

    while (counter++ < 30) {
        last_square = i * i;
        sum_of_squares += last_square;
        if (i >= n) {
            break;
        }
        i++;
    }

    // Verify that the sum of squares is greater than or equal to the last square added
    __VERIFIER_assert(sum_of_squares >= last_square);

    printf("Sum of squares: %d, Last square: %d\n", sum_of_squares, last_square);
    return 0;
}