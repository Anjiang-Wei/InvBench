#include <stdio.h>
#include <stdlib.h>

// Function prototypes for nondeterministic inputs
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Custom assertion to mimic __VERIFIER_assert
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        __assert_fail("Assertion failed!", "GeneratedProgram.c", __LINE__, __func__);
    }
}

// Error function to simulate a reach error in verification tools
void reach_error() {
    __assert_fail("0", "GeneratedProgram.c", 6, "reach_error");
}

// Function to simulate some meaningful computational logic
int compute(int x, int y) {
    int result = 0;
    for (int i = 0; i < x; i++) {
        result += y;
    }
    return result;
}

int main(void) {
    // Nondeterministic input values
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Constraints for the inputs
    if (a < 0 || a > 10) {
        return 0;
    }
    if (b < 0 || b > 5) {
        return 0;
    }

    // Call the compute function
    int result = compute(a, b);

    // Loop with an assertion to be checked by verification tools
    for (int i = 0; i < result; i++) {
        __VERIFIER_assert(i <= result);
    }

    // Check if the result satisfies a certain condition
    if (result > 50) {
        reach_error();
        abort();
    }

    return 0;
}