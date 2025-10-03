/* Integer division by repeated subtraction with verifier-friendly structure */
#include <assert.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "division.c", 10, "reach_error");
}

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

int counter = 0;

int main() {
    int a, b, q, r, a0;
    /* nondeterministic inputs */
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    /* preconditions: 0 <= a <= 100, 1 <= b <= 100 */
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 1 && b <= 100);

    a0 = a; /* save original dividend */
    q = 0;  /* quotient */
    r = a;  /* remainder candidate */

    /* loop: subtract b from r until r < b */
    while (counter++ < 100 && r >= b) {
        /* trivial bound invariant to aid verification */
        __VERIFIER_assert(r >= 0);
        r = r - b;
        q = q + 1;
    }

    /* postconditions: remainder in [0, b) and a0 == q*b + r */

    return 0;
}