#include <stdio.h>
#include <stdlib.h>

// External functions to simulate non-deterministic input and assertion failures
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 6, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

// Assertion function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// A function to calculate a pseudo-random transformation on a number
int transform(int x) {
    if (x % 2 == 0) {
        return x / 2;
    } else {
        return 3 * x + 1;
    }
}

// A function to simulate a computational task that behaves differently based on input
int compute_task(int input) {
    int counter = 0;
    while (input != 1 && counter < 1000) {
        input = transform(input);
        counter++;
    }
    return counter;
}

int main() {
    // Read a non-deterministic integer
    int input = __VERIFIER_nondet_int();

    // Constraints on the input
    if (input <= 0) {
        input = 1;
    }

    // Perform the task
    int result = compute_task(input);

    // Assert that the transformations do not exceed a certain number of steps
    __VERIFIER_assert(result < 1000);

    // Check for a specific condition to ensure correctness
    if (input < 10 && result > 100) {
    ERROR : {
        reach_error();
        abort();
    }
    }

    printf("Input: %d, Steps: %d\n", input, result);

    return 0;
}