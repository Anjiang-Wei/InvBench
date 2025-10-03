// Fibonacci sequence and Cassini's identity verification

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fib_cassini.c", 10, "reach_error"); }

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
    return;
}

int main() {
    // pick n nondeterministically, but constrain it so Fibonacci fits in 64 bits
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 2 && n <= 92);

    // compute F(0)=0, F(1)=1, …, up to F(n)
    long long f_prev = 0; // F(i-1)
    long long f_curr = 1; // F(i)
    long long f_next = 0; // temporary for F(i+1)
    int i = 2;
    while (i <= n) {
        f_next = f_prev + f_curr;
        f_prev = f_curr;
        f_curr = f_next;
        ++i;
    }

    // at this point:
    //   f_curr       = F(n)
    //   f_prev       = F(n-1)
    //   f_prev+f_curr = F(n+1)
    long long fn = f_curr;
    long long fn1 = f_prev;           // F(n-1)
    long long fnp1 = f_prev + f_curr; // F(n+1)

    // Cassini's identity: F(n-1)*F(n+1) − F(n)^2 = (−1)^n
    long long lhs = fn1 * fnp1 - fn * fn;
    long long rhs = (n % 2 == 0) ? 1LL : -1LL;
    __VERIFIER_assert(lhs == rhs);

    return 0;
}