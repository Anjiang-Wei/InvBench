/*
  Sum of squares
  Computes x = sum_{i=1..k} i^2
  Verifies at each step that 6*x == c*(c+1)*(2*c+1)
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sumsq.c", 10, "reach_error");
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
    int k;
    long long c, x;

    /* nondeterministic bound for k */
    k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 0 && k <= 1000);

    /* initialize counter and accumulator */
    c = 0;
    x = 0;

    while (1) {
        /* check the relation 6*x == c*(c+1)*(2*c+1) holds */
        __VERIFIER_assert(6 * x == c * (c + 1) * (2 * c + 1));

        /* break when we've summed up to k */
        if (!(c < k)) {
            break;
        }

        /* step: include next square */
        c = c + 1;
        x = x + c * c;
    }

    /* final check: after loop x == sum_{i=1..k} i^2 */

    return 0;
}