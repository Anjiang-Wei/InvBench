/*
  Sum of squares: computes S = sum_{j=0..N} j^2
  Verifies that 6*S == N*(N+1)*(2*N+1)
*/
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sum_squares.c", 9, "reach_error");
}
extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int N;
    long long i, s;

    N = __VERIFIER_nondet_uint();
    assume_abort_if_not(N <= 20);

    i = 0;
    s = 0;

    while (1) {
        /* ensure 6*s == (i-1)*i*(2*i-1) */
        __VERIFIER_assert(6 * s == (i - 1) * i * (2 * i - 1));
        if (!(i <= (long long)N)) {
            break;
        }
        s = s + i * i;
        i = i + 1;
    }
    /* at exit, i == N+1, and s == sum_{j=0..N} j^2 */
    return 0;
}