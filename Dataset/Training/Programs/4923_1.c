#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int M = __VERIFIER_nondet_int();
    assume_abort_if_not(M >= 1 && M <= 1000000);

    int X_start = __VERIFIER_nondet_int();
    assume_abort_if_not(X_start >= 1 && X_start <= 1000);

    int X = X_start;
    int sum = 0;
    int product = 1;

    for (int i = 1; i <= M; i++) {
        if (X % 2 == 0) {
            sum += X;
        } else {
            product *= X;
            if (product > 100000) {
                product = product % 100000; // modulo to prevent overflow
            }
        }

        X = (X * i) % 1000 + 1; // change X for iteration to keep within range
    }

    // Check theoretical properties without revealing loop invariants
    int is_even = sum % 2 == 0;
    int product_threshold = product < 100000;

    // These assertions allow the verification tool to analyze properties of the program
    __VERIFIER_assert(is_even || !product_threshold);

    return 0;
}