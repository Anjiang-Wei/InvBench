#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

// Function to assume conditions for verification
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function stub that returns a nondeterministic integer
int __VERIFIER_nondet_int();

// Function to assert a condition, to simulate verification checks
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int a, b;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);
    assume_abort_if_not(b > a);

    int sum = 0;
    int product = 1;
    int i = 0;

    while (i < b) {
        if (i >= a) {
            sum += i;
            product *= 2; // Increase product exponentially as an example logic
        }
        i++;
    }

    // Ensure the calculations are in an expected state
    __VERIFIER_assert(sum >= 0);    // Sum should be non-negative
    __VERIFIER_assert(product > 0); // Product should be greater than 0

    printf("Final sum: %d\n", sum);
    printf("Final product: %d\n", product);

    return 0;
}