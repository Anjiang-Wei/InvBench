#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Function to simulate an error reaching mechanism similar to those in examples
void reach_error() { __assert_fail("0", "custom.c", 12, "reach_error"); }

// Function to assert a condition and call reach_error if the condition is false
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

// Example of non-deterministic integer generator stub
extern int __VERIFIER_nondet_int(void);

// Example of non-deterministic boolean generator stub
extern _Bool __VERIFIER_nondet_bool(void);

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // Assume that a and b are non-negative for meaningful calculations
    if (a < 0 || b < 0) {
        return 0;
    }

    // Loop that performs computation with unknown inputs
    while (__VERIFIER_nondet_bool()) {
        a = a - 1;                  // decrement a
        b = b + 2;                  // increment b
        sum += b;                   // accumulate sum
        product *= (b > 0) ? b : 1; // accumulate product, avoid multiplying by zero
    }

    // Assertion to check properties or conditions on the computed values
    __VERIFIER_assert(sum >= 0 && product >= 1);

    return 0;
}