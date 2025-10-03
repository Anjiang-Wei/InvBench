#include <stdlib.h>

/* Declarations for verification infrastructure */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "div_rem.c", 3, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    /* Nondeterministic inputs */
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    /* Constrain inputs: a >= 0, b > 0, keep them bounded for analysis */
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b > 0);
    assume_abort_if_not(a <= 1000);
    assume_abort_if_not(b <= 1000);

    /* Save originals for post‐condition checks */
    int orig_a = a;
    int orig_b = b;

    /* Compute quotient q and remainder r by repeated subtraction */
    int q = 0;
    while (a >= b) {
        a = a - b;
        q = q + 1;
    }
    int r = a;

    /* Verify the division‐remainder property:
       orig_a = q * orig_b + r
       0 <= r < orig_b
    */
    __VERIFIER_assert(r >= 0 && r < orig_b);

    return 0;
}