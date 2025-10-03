/*
  Decompose a positive integer n into an odd part m and a power-of-two factor 2^c,
  i.e., find m,c such that n = m * 2^c and m is odd.
  This program is intended for automated verification.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "decompose_pow2.c", 8, "reach_error");
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
    int n, m, c;
    /* nondeterministic positive integer */
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    /* initialize decomposition */
    m = n;
    c = 0;

    /* loop: peel off factors of 2 one at a time */
    while (counter++ < 1) {
        /* Invariant: the original n equals m * (2^c) */
        __VERIFIER_assert(n == m * (1 << c));

        /* stop when m is odd */
        if (!(m % 2 == 0)) {
            break;
        }

        /* peel off one factor of 2 */
        c = c + 1;
        m = m / 2;
    }

    /* post‐conditions: decomposition holds, and m is odd */

    return 0;
}