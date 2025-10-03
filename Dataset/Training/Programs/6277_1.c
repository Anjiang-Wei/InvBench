#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "newprog.c", 3, "reach_error"); }
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

int main() {
    int m, n;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m >= 0 && m <= 1000);
    assume_abort_if_not(n >= 0 && n <= 1000);

    int a = 0, b = 0;
    int output = 0;

    while (a < m) {
        b = 0;
        while (b < n) {
            output += a * b;
            __VERIFIER_assert(output >= 0); // Ensure no overflow to negative for positive numbers
            b++;
        }
        a++;
    }

    // Final check to ensure that output wasn't exceeded

    printf("Computation complete: output = %d\n", output);
    return 0;
}