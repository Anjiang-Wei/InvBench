#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_check.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int() {
    // Simulating a nondeterministic input for testing and verification
    return rand() % 10 + 1; // Generates a number between 1 and 10
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(void) {
    int n = 5; // We want to calculate factorial of 5
    int result = factorial(n);

    // Verify factorial calculation correctness
    __VERIFIER_assert(result == 120);

    // Example loop to simulate state change, similar to previous examples
    int state = 0;
    int input_change_count = 0;

    while (input_change_count < 10) {
        int input = __VERIFIER_nondet_int();
        state += input;
        input_change_count++;
    }

    printf("Final state: %d\n", state);

    return 0;
}