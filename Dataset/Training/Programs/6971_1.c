#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// A function to generate a sequence where each step increases by a given value
int generate_sequence(int initial, int increment, int steps) {
    int value = initial;

    for (int i = 0; i < steps; i++) {
        value += increment;
        assume_abort_if_not(value >= 0); // Ensure the value doesn't underflow
    }

    return value;
}

int main() {
    int start, inc, steps, result;

    // Get nondeterministic inputs
    start = __VERIFIER_nondet_int();
    inc = __VERIFIER_nondet_int();
    steps = __VERIFIER_nondet_int();

    // Arbitrary assumptions for the input variables
    assume_abort_if_not(start >= 0 && start <= 100);
    assume_abort_if_not(inc >= 1 && inc <= 10);
    assume_abort_if_not(steps >= 1 && steps <= 10);

    // Generate sequence starting from 'start', incrementing by 'inc' for 'steps' steps
    result = generate_sequence(start, inc, steps);

    // Check that the result is within expected bounds
    __VERIFIER_assert(result == start + inc * steps);

    printf("Final result: %d\n", result);

    return 0;
}