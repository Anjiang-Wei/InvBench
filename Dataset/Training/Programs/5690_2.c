#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main(void) {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Assume some initial conditions
    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);
    assume_abort_if_not(b < a);

    // Initialize the result variable
    int result = 0;

    // Perform Euclidean algorithm to find gcd
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    result = a; // gcd result

    // Check post conditions
    __VERIFIER_assert(a % result == 0 && b % result == 0);

    printf("The gcd is: %d\n", result);

    return 0;
}