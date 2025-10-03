// Fibonacci Computation and Verification of Cassini's Identity
// Verifier-friendly C program

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "fib_cassini.c", 7, "reach_error");
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
    int k = __VERIFIER_nondet_int();
    long long prev, curr;
    int i;

    // We only consider 0 <= k <= 40 to avoid overflow of Fibonacci numbers in 64-bit
    assume_abort_if_not(k >= 0 && k <= 40);

    prev = 0; // Will hold F(n)
    curr = 1; // Will hold F(n+1)
    i = 0;

    while (i < k) {
        long long next = prev + curr; // F(n+2) = F(n) + F(n+1)
        prev = curr;                  // shift: new F(n)
        curr = next;                  // shift: new F(n+1)
        i = i + 1;
    }

    // At this point: prev = F(k), curr = F(k+1)
    // Cassini's identity: F(k+1)*F(k-1) - F(k)^2 = (-1)^k
    // And F(k-1) = F(k+1) - F(k)
    __VERIFIER_assert(
        curr * (curr - prev) - prev * prev == ((k % 2 == 0) ? 1 : -1));

    return 0;
}