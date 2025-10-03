// Extended Euclidean Algorithm: computes g = gcd(a0, b0)
// and finds x, y such that a0*x + b0*y = g

#include <assert.h>
#include <limits.h>
extern void abort(void);
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // Non-deterministic inputs
    int a0 = __VERIFIER_nondet_int();
    int b0 = __VERIFIER_nondet_int();
    // restrict to non-negative and not both zero
    assume_abort_if_not(a0 >= 0 && b0 >= 0 && (a0 > 0 || b0 > 0));

    // Copy inputs into working variables
    int a = a0;
    int b = b0;
    // Coefficients for the combinations:
    // invariant: a0*x0 + b0*y0 = a
    //            a0*x1 + b0*y1 = b
    int x0 = 1, y0 = 0;
    int x1 = 0, y1 = 1;

    // Standard loop of the extended Euclidean algorithm
    while (b != 0) {
        int q = a / b;
        int r = a % b;
        // update coefficients
        int x2 = x0 - q * x1;
        int y2 = y0 - q * y1;
        // shift for next iteration
        a = b;
        b = r;
        x0 = x1;
        y0 = y1;
        x1 = x2;
        y1 = y2;
    }

    // At termination, 'a' is gcd(a0,b0)
    // and x0,y0 satisfy a0*x0 + b0*y0 = a
    __VERIFIER_assert(a > 0);

    return 0;
}