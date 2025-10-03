extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fib_pow2.c", 4, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

/*
 * This program computes the n-th Fibonacci number (fib_prev after the loop)
 * and 2^n (pow2), both by simple iteration, and then asserts the known
 * inequality fib(n) <= 2^n.  The loop is bounded by n<=30 to avoid overflow.
 */
int main() {
    int n, i;
    int fib_prev, fib_cur, tmp;
    int pow2;

    /* n is chosen non-deterministically, but constrained to [0,30] */
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 30);

    /* Initialize for Fibonacci: fib_prev = fib(0), fib_cur = fib(1) */
    fib_prev = 0;
    fib_cur = 1;
    /* Initialize power of two: 2^0 = 1 */
    pow2 = 1;
    i = 0;

    /* Iterate n times:
       - update (fib_prev, fib_cur) to (fib(i), fib(i+1))
       - update pow2 to 2^i
    */
    while (i < n) {
        tmp = fib_cur + fib_prev;
        fib_prev = fib_cur;
        fib_cur = tmp;
        pow2 = pow2 * 2;
        i++;
    }

    /* At this point fib_prev == fib(n) and pow2 == 2^n */
    __VERIFIER_assert(fib_prev <= pow2);

    return 0;
}