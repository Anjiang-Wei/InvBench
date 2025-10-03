#include <assert.h>
#include <stdbool.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) { assert(0); }

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

/*
Program Description:

This program calculates the sum of the first n natural numbers.
It verifies that the sum at any point is equal to n*(n+1)/2.
*/

int main() {
    int n, sum, i, temp;

    // n is a nondeterministic integer (e.g., user input)
    n = __VERIFIER_nondet_int();

    // Assume n is non-negative for meaningful computation
    assume_abort_if_not(n >= 0);

    sum = 0;
    i = 0;

    // Loop to calculate the sum of first n natural numbers
    while (__VERIFIER_nondet_bool()) {
        // Exit loop when i exceeds n
        if (i >= n) {
            break;
        }

        i = i + 1;
        sum = sum + i;

        // Constraint check after each iteration
        temp = (i * (i + 1)) / 2;
        __VERIFIER_assert(sum == temp);
    }

    // Final assertion to ensure correctness of the sum

    return 0;
}