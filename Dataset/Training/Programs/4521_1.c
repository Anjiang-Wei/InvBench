#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function to perform a bounded increment operation
// Variables x and y must remain within specified bounds, else an error is reached.
void bounded_increment(int *x, int *y, int bound) {
    if (*x < bound) {
        (*x)++;
    } else {
        (*y)++;
    }
}

int main() {
    int a = 0, b = 0, bound = 100;
    int check_value = 0;

    // Main loop that increments the values of a and b
    while (a < 1000) {
        bounded_increment(&a, &b, bound);

        // Simulate a check that should always hold
        if ((a + b) % 2 == 0) {
            check_value++;
        }
    }

    // Adjust b and maintain a condition
    while (b > 0) {
        a--;
        b--;
        check_value--;
    }

    // Assert that the check_value is equal to a certain expected constant
    __VERIFIER_assert(check_value == a);

    return 0;
}