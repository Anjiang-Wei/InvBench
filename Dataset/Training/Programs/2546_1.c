// This program is designed for analysis and verification, demonstrating floating-point operations and constraints.

#include <math.h>
#include <stdint.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        { reach_error(); }
        abort();
    }
}

// Function to simulate some floating-point operations
float controlled_float_op(float a, float b) {
    if (a > 100.0f || b > 100.0f) {
        return NAN;
    }

    float result = a + b;
    unsigned int counter = 0;

    while (fabs(result) < 50.0f && counter < 5) {
        result *= 2.0f;
        counter++;
    }

    return result;
}

// Check if the float is a NaN
int isnan_float(float x) {
    return x != x;
}

int main() {
    // Test values
    float a = 10.0f;
    float b = 20.0f;

    // Perform the operation
    float result = controlled_float_op(a, b);

    // Assertions for verification
    if (isnan_float(result)) {
        // If the result is NaN, ensure both a and b were above 100.0
        if (a <= 100.0f && b <= 100.0f) {
            __VERIFIER_assert(0); // This should not happen
        }
    } else {
        // If the result is valid, ensure it's within an expected range
        __VERIFIER_assert(result >= 50.0f && result <= 400.0f);
    }

    printf("Operation completed. Result: %f\n", result);
    return 0;
}