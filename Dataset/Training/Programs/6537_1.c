// Extended Euclidean algorithm with verification-friendly structure
#include <assert.h>
extern void abort(void);

/* Error handling and verification intrinsics */
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    /* Nondeterministic inputs, but constrained to avoid overflows */
    int a0 = __VERIFIER_nondet_int();
    int b0 = __VERIFIER_nondet_int();
    assume_abort_if_not(a0 >= 1 && a0 <= 1000);
    assume_abort_if_not(b0 >= 1 && b0 <= 1000);

    /* Initialize for extended GCD */
    int a = a0;
    int b = b0;
    int x0 = 1, y0 = 0;
    int x1 = 0, y1 = 1;

    /* Compute gcd(a0,b0) and coefficients x0,y0 such that
       a0*x0 + b0*y0 == gcd(a0,b0) */
    while (b != 0) {
        int q = a / b;
        int r = a % b;
        int x2 = x0 - q * x1;
        int y2 = y0 - q * y1;

        /* Advance the tuple (a,b), (x0,y0), (x1,y1) */
        a = b;
        b = r;
        x0 = x1;
        y0 = y1;
        x1 = x2;
        y1 = y2;
    }

    /* At termination, a == gcd(a0,b0) and
       a0*x0 + b0*y0 == a holds */
    __VERIFIER_assert(a >= 1);

    return 0;
}