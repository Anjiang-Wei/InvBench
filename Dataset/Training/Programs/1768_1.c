#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated-program.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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
    int a, b, i;
    a = 0;
    b = 0;
    i = 0;

    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000); // Ensure n is within a reasonable range

    while (i < n) {
        // Perform some computations
        a = a + 2;
        b = b + a;

        // Ensure the relationship between a and b holds
        __VERIFIER_assert(b == i * (i + 1) + a);

        i++;
    }

    // Final assertion to ensure cumulative consistency
    return 0;
}