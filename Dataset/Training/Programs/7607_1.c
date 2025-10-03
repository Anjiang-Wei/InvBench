#include <stdio.h>
#include <stdlib.h>

// Definitions for verification functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 4, "reach_error"); }

// Function for non-deterministic integer generation
extern int __VERIFIER_nondet_int(void);

// Function for aborting execution if a condition is not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to simulate assertions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

// Main function
int main() {
    int a, b, t1, t2;
    long long sum_of_squares;

    // Non-deterministic assignment
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume constraints for verification
    assume_abort_if_not(a > 0 && a < 50);
    assume_abort_if_not(b > 0 && b < 50);

    t1 = a;
    t2 = b;
    sum_of_squares = 0;

    // Sum of squares loop
    while (t1 > 0 || t2 > 0) {
        if (t1 > 0) {
            sum_of_squares += t1 * t1;
            t1--;
        }
        if (t2 > 0) {
            sum_of_squares += t2 * t2;
            t2--;
        }
    }

    // Assert to check if computation was valid
    __VERIFIER_assert(sum_of_squares >= a * a + b * b); // sum should be at least initial squares
    printf("Sum of squares: %lld\n", sum_of_squares);

    return 0;
}