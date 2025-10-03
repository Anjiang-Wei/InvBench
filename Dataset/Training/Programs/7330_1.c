#include <stdio.h>

// External functions for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_new.c", 6, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Main function demonstrating a number sequence verification
int main() {
    int limit = 15;
    int total = 0;
    int count = 0;
    int current = 1;

    // This loop calculates the sum of the first 'limit' natural numbers
    while (count < limit) {
        total += current;
        count++;
        current++;
    }

    // Now, verify if the sum of the first 'limit' natural numbers
    // matches the formula n(n+1)/2
    __VERIFIER_assert(total == (limit * (limit + 1)) / 2);

    // Output the result to verify the computation
    printf("Sum of first %d natural numbers is: %d\n", limit, total);

    return 0;
}