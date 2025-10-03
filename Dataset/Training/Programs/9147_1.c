#include <stdio.h>

// Mock assertion handling to mimic typical program analysis framework usage
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_program.c", 6, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
        abort(); // Stop execution in error state
    }
    return;
}

// Mock nondeterministic integer generator
extern int __VERIFIER_nondet_int(void);

int main() {
    // Using nondeterministic numbers for variety in initial conditions
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0, prod = 1;
    int i = 0;

    // Loop to compute the sum and product of numbers up to a certain limit
    while (i < 5) {
        if (a > 0 && b > 0) {
            sum += i;        // Accumulate the sum of indices
            prod *= (i + 1); // Accumulate the product of indices (offset by 1 for illustration)
        }
        i++;
    }

    // Assert statements that help analysis but aren't trivial loop invariant
    __VERIFIER_assert(sum >= 0); // Sum should be non-negative
    __VERIFIER_assert(prod > 0); // Product should be positive after looping

    // Output the final computed values
    printf("Final Sum: %d\n", sum);
    printf("Final Product: %d\n", prod);

    return 0;
}