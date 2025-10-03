#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void); // Simulates non-deterministic integer input
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    // Use the reach_error function if the condition is not satisfied
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int a, b, limit;
    long long sum, product;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    limit = __VERIFIER_nondet_int();

    // Assume some realistic constraints
    assume_abort_if_not(limit > 0 && limit <= 100);
    assume_abort_if_not(a >= 0 && b >= 0);

    sum = a + b;
    product = a * b;

    int i = 0;
    while (i < limit) {
        sum += (a + i);
        product *= (b + i);

        // Some meaningful assertions which can be verified

        i++;
    }

    // Final verification step
    __VERIFIER_assert(sum >= a + b);

    return 0;
}