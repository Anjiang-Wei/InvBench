#include <stdio.h>
#include <stdlib.h>

// External functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed_program.c", 3, "reach_error"); }
unsigned int __VERIFIER_nondet_uint();
_Bool __VERIFIER_nondet_bool();

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
    unsigned int a = 1;
    unsigned int b = 1;
    unsigned int count = 0;
    unsigned int threshold = __VERIFIER_nondet_uint();

    // Limit the threshold to a feasible range for analysis
    if (threshold > 50) {
        threshold = 50;
    }

    while (a < threshold) {
        a *= 2;
        b += a;
        count++;
    }

    // Check if the number of iterations matches expected logic
    __VERIFIER_assert(count <= 6);

    // Simulate some post-loop constraint check
    if (a >= 32) {
    }

    printf("Final values: a = %u, b = %u, count = %u\n", a, b, count);
    return 0;
}