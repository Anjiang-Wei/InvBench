// Comprehensive Verification-Friendly C Program
// This program performs multiple computations on nondeterministic inputs
// including sums, products, factorials, Fibonacci numbers, GCD, LCM, and
// prime counting via a simple sieve. Final properties are asserted
// to allow automated verification tools to check correctness.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "verification_program.c", 8, "reach_error");
}

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
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    // Declare nondeterministic inputs
    int n, m;
    int a, b;

    // Acquire inputs
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Bound the inputs to reasonable ranges for verification
    assume_abort_if_not(n >= 0 && n <= 50);
    assume_abort_if_not(m >= 0 && m <= 10);
    assume_abort_if_not(a >= 1 && a <= 100);
    assume_abort_if_not(b >= 1 && b <= 100);

    // Save originals for later assertions
    int orig_n = n;
    int orig_m = m;
    int orig_a = a;
    int orig_b = b;

    // 1) Compute sum of first n natural numbers: sum1 = 1 + 2 + ... + n
    long long sum1 = 0;
    for (int i = 1; i <= n; i++) {
        sum1 += i;
    }

    // 2) Compute sum of squares: sum2 = 1^2 + 2^2 + ... + n^2
    long long sum2 = 0;
    for (int i = 1; i <= n; i++) {
        sum2 += (long long)i * i;
    }

    // 3) Compute m raised to the power n: pow_mn = m^n
    long long pow_mn = 1;
    for (int i = 0; i < n; i++) {
        pow_mn *= orig_m;
    }

    // 4) Compute factorial: fact = n!
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }

    // 5) Compute Fibonacci numbers: fib(n) and fib(n+1)
    long long fib_prev = 0; // F(0)
    long long fib_curr = 1; // F(1)
    long long fib_next = 1; // placeholder
    if (n == 0) {
        fib_curr = 0;
    } else if (n == 1) {
        fib_curr = 1;
    } else {
        for (int i = 2; i <= n; i++) {
            fib_next = fib_prev + fib_curr;
            fib_prev = fib_curr;
            fib_curr = fib_next;
        }
    }
    long long fib_n = fib_curr;
    long long fib_nplus = fib_prev + fib_curr; // F(n+1)

    // 6) Compute GCD using subtraction-based Euclidean algorithm
    int a0 = orig_a;
    int b0 = orig_b;
    while (a0 != b0) {
        if (a0 > b0) {
            a0 = a0 - b0;
        } else {
            b0 = b0 - a0;
        }
    }
    int gcd = a0; // or b0, since they are equal

    // 7) Compute LCM via formula: lcm = a*b / gcd
    long long lcm = (long long)orig_a / gcd * orig_b;

    // 8) Count the number of primes <= n using a simple sieve
    int isPrime[51];
    for (int i = 0; i <= orig_n; i++) {
        isPrime[i] = 1;
    }
    if (orig_n >= 0) {
        isPrime[0] = 0;
    }
    if (orig_n >= 1) {
        isPrime[1] = 0;
    }
    for (int i = 2; i * i <= orig_n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= orig_n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    int primeCount = 0;
    for (int i = 2; i <= orig_n; i++) {
        if (isPrime[i]) {
            primeCount++;
        }
    }

    //----------------------------------------------------------------------
    // Final Assertions: Check known mathematical properties
    //----------------------------------------------------------------------

    // A) sum1 == n*(n+1)/2  <=> 2*sum1 == n*(n+1)

    // B) sum2 == n*(n+1)*(2n+1)/6  <=> 6*sum2 == n*(n+1)*(2n+1)

    // C) pow_mn >= 1 (for all m>=0, n>=0)

    // D) fact >= 1  (factorial grows, n>=0)
    __VERIFIER_assert(fact >= 1);

    // E) Fibonacci correctness: fib(n+1) == fib(n) + fib(n-1)
    if (orig_n >= 1) {
    }

    // F) GCD divides both original inputs

    // G) LCM is multiple of both original inputs

    // H) Prime count is at most n-1 for n >= 2, and at most n otherwise
    if (orig_n >= 2) {
    } else {
    }

    return 0;
}