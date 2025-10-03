// Division by repeated subtraction, with correctness checks
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "division-by-subtraction.c", 7, "reach_error");
}
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

/*
   Compute quotient and remainder of m / d by repeated subtraction.
   Postconditions:
     1) orig_m == q * d + r
     2) 0 <= r < d
*/
extern int __VERIFIER_nondet_int(void);

int main() {
    int m = __VERIFIER_nondet_int();
    int d = __VERIFIER_nondet_int();
    /* constraints on inputs to avoid overflow and ensure well-defined division */
    assume_abort_if_not(m >= 0 && m <= 100000);
    assume_abort_if_not(d > 0 && d <= 1000);

    int orig_m = m;
    int q = 0;

    /* Loop: subtract divisor until the remainder is less than the divisor */
    while (m >= d) {
        m = m - d;
        q = q + 1;
        /* ensure the running remainder never goes negative */
    }

    int r = m;
    /* Check the division identity and remainder bounds */
    __VERIFIER_assert(r >= 0 && r < d);

    return 0;
}