#include <stdio.h>
#include <stdlib.h>

// External functions for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "generated_program.c", 5, "reach_error");
}

// Nondeterministic input generator (for verification tools)
extern int __VERIFIER_nondet_int(void);

// A function to assert conditions during runtime
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

// Function to perform some meaningful computation
int calculate(int a, int b) {
    int sum = 0, i;

    for (i = 0; i < b; i++) {
        sum += a;
    }

    return sum;
}

int main() {
    // Declare variables
    int a, b, result;

    // Get nondeterministic inputs
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume some condition for the inputs
    if (b < 0 || b > 10) {
        return 0; // Abort if the assumption is violated
    }

    // Calculate the result
    result = calculate(a, b);

    // Assert some expected properties
    __VERIFIER_assert(result == a * b);

    // Print the result for manual inspection
    printf("The result of %d * %d is %d\n", a, b, result);

    return 0;
}