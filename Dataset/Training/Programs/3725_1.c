#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int();

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
    return;
}

int main() {
    int p = __VERIFIER_nondet_int();
    int q = __VERIFIER_nondet_int();

    // Assuming some constraints on p and q
    assume_abort_if_not(p >= 0 && p <= 100);
    assume_abort_if_not(q >= 10 && q <= 200);

    int result = 0;
    int i = 0;

    // Computation: Accumulate multiples of 'q' while ensuring result doesn't overflow
    while (i < p && result < 1000) {
        result += q;
        __VERIFIER_assert(result <= i * q + q); // placeholder assert, not an invariant of the loop
        i++;
    }

    // Ensures that if loop ends, the result is bounded as expected

    printf("Result: %d\n", result);

    return 0;
}