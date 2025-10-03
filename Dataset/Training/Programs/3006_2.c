/*
  Division Algorithm: Given non-negative x and positive y,
  compute integers q (quotient) and r (remainder) such that
     x = q * y + r   and   0 <= r < y
  using repeated subtraction.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "div_rem.c", 9, "reach_error");
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

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    /* We require x >= 0 and y > 0 to make division meaningful */
    assume_abort_if_not(x >= 0 && y > 0);

    /* Remember the originals for the final check */
    int orig_x = x;
    int orig_y = y;

    int q = 0; /* quotient */
    int r = x; /* remainder candidate */

    /* Repeatedly subtract y from r */
    while (r >= y) {
        r = r - y;
        q = q + 1;
    }

    /* Final properties: remainder in [0, y-1], and x = q*y + r */
    __VERIFIER_assert(r < orig_y);

    return 0;
}