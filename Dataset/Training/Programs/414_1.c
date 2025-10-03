/*
 * Example C program designed for automated verification tools
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 8, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int x, y, z;
    long long sum = 0;
    int max_iterations = __VERIFIER_nondet_int();

    assume_abort_if_not(max_iterations > 0 && max_iterations < 1000);

    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    z = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0 && y >= 0 && z >= 0);

    for (int i = 0; i < max_iterations; i++) {
        sum += x * i + y * i + z * i;
        if (sum < 0) {
            reach_error();
        }
    }

    // Example property: sum should never be negative
    __VERIFIER_assert(sum >= 0);

    printf("Computation completed with sum: %lld\n", sum);
    return 0;
}