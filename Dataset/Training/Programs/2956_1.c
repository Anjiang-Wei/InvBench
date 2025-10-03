// fib_cassini.c
// This program computes Fibonacci numbers up to N (2 ≤ N ≤ 92) and
// checks Cassini's identity: F(i-1)*F(i+1) - F(i)^2 == (-1)^i for each i.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "fib_cassini.c", 8, "reach_error");
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
    int N = __VERIFIER_nondet_int();
    // We need at least two Fibonacci numbers and avoid overflow of 64-bit
    assume_abort_if_not(N >= 2 && N <= 92);

    long long f0 = 0; // F(0)
    long long f1 = 1; // F(1)
    long long f2;     // will hold F(i+1)
    int i;

    // Compute Fibonacci numbers F(2), F(3), ..., F(N)
    // and check Cassini's identity at each step.
    for (i = 1; i < N; i++) {
        // f2 = F(i+1)
        f2 = f0 + f1;

        // Cassini's identity:
        //    F(i-1)*F(i+1) - F(i)^2 == (-1)^i
        // Here f0 = F(i-1), f1 = F(i), f2 = F(i+1)
        __VERIFIER_assert(f0 * f2 - f1 * f1 == ((i % 2 == 0) ? 1 : -1));

        // shift window: F(i-1)←F(i), F(i)←F(i+1)
        f0 = f1;
        f1 = f2;
    }

    return 0;
}