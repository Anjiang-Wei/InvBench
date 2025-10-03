#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "synthetic-ll.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, c;
    long long sum, prod;

    // Non-deterministic input values
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Assumptions to ensure meaningful computation
    assume_abort_if_not(a > 0 && b >= 0 && c >= 0);
    assume_abort_if_not(a < 20 && b < 20 && c < 20);

    sum = 0;
    prod = 1;

    // Loop with meaningful computation
    for (int i = 0; i < a; i++) {
        sum += b;
        prod *= c;

        // Check computational constraint within the loop
        if (prod > 1000) {
            break;
        }
    }

    // Verifying the computation
    // Here we use invariants or conditions to ensure correctness
    if (a % 2 == 0) {
        __VERIFIER_assert(sum >= 0);
    } else {
    }

    printf("Sum: %lld, Prod: %lld\n", sum, prod);
    return 0;
}