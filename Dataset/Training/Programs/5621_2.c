#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    unsigned int a = 1;
    unsigned int b = 1;
    unsigned int result1 = 0;
    unsigned int result2 = 0;
    unsigned int i = 0;

    // Loop 1: Calculate factorial of a number
    for (i = 1; i <= 5; i++) {
        a *= i;
    }
    result1 = a; // Should be 120 (5!)

    // Loop 2: Compute sum of consecutive numbers
    for (i = 1; i <= 10; i++) {
        b += i;
    }
    result2 = b; // Should be 56 (1+2+...+10 + initial b=1)

    // Constraint: Ensure a predictable computation, check the results
    // This assertion should pass if b computation is correct
    __VERIFIER_assert(result2 == 56);

    return 0;
}