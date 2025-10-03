/*
 * This program calculates a simple Fibonacci sequence up to a maximum number and verifies certain conditions.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_example.c", 10, "reach_error"); }
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
extern int __VERIFIER_nondet_int(void);

int main() {
    unsigned int max_steps;
    long long fib1, fib2, fib_next, steps;

    max_steps = __VERIFIER_nondet_int();
    assume_abort_if_not(max_steps >= 1 && max_steps <= 5); // Limiting steps for deterministic behavior

    fib1 = 0;
    fib2 = 1;
    steps = 0;

    while (steps < max_steps) {
        fib_next = fib1 + fib2;

        // Check some properties
        fib2 = fib_next;
        steps++;
    }

    // Verify result after the loop
    __VERIFIER_assert(fib1 <= fib2 && fib2 >= 0); // fib1 and fib2 should be in increasing order and be non-negative
    return 0;
}