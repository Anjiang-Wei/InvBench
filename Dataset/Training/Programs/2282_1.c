#include <stdio.h>
#include <stdlib.h>

// Define a few symbolic constants
#define MAX_ITER 100

// Define a function that will be used for assertions
void reach_error() { __assert_fail("[ERROR] Assertion failed", "example_program.c", __LINE__, __func__); }
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
    return;
}

int main() {
    // Variables for our program logic
    int x = 0;
    int y = 0;
    int z = 0;
    int a = 0;
    int iter_count = 0;

    // Main loop, which will perform some operations and check constraints
    while (iter_count < MAX_ITER) {
        // Perform some operations
        x += 2;
        y += 3;

        // Apply a meaningful condition
        if (x % 5 == 0 && y % 5 == 0) {
            z += 5;
        }

        // Introduce a constraint to check
        if (z >= 15) {
            a = z / 3;
        }

        // Use assertions to enforce constraints that could be verified by tools
        __VERIFIER_assert(a >= 0);

        iter_count++;
    }

    // Final check to assert expected outcomes

    return 0;
}