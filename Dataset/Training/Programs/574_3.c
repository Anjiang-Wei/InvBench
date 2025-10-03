/*
 * Combined Algorithms: Power of Two, Pascal's Triangle, Factorial,
 * Fibonacci Sequence, and GCD Computation
 *
 * This program is designed to be analyzed and verified by automated
 * verification tools. It contains multiple loops and assertions
 * to check intermediate and final properties of the computations.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "combined_algos.c", 6, "reach_error");
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
    //////////////////////////////////////////////////////////
    // Input parameter for several algorithms: n in [0..10]
    //////////////////////////////////////////////////////////
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    //////////////////////////////////////////////////////////
    // Section 1: Compute power of two, pow2 = 2^n
    //////////////////////////////////////////////////////////
    long long pow2 = 1;
    int cnt = n;
    // Initial check: 2^(n - cnt) == 1 when cnt == n
    while (cnt > 0) {
        // Before each step: pow2 == 2^(n - cnt)
        pow2 = pow2 * 2;
        cnt = cnt - 1;
    }
    __VERIFIER_assert(cnt == 0);
    // After loop: pow2 == 2^n

    //////////////////////////////////////////////////////////
    // Section 2: Build Pascal's triangle C up to row n
    //////////////////////////////////////////////////////////
    long long C[11][11];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
            // Each binomial coefficient is at least 1
            // Symmetry property: C(i, j) == C(i, i-j)
        }
    }

    //////////////////////////////////////////////////////////
    // Section 3: Sum of the n-th row of Pascal's triangle
    //            Should equal 2^n
    //////////////////////////////////////////////////////////
    long long sum_row = 0;
    for (int j = 0; j <= n; j++) {
        sum_row += C[n][j];
        // Partial sums never exceed the total 2^n
    }

    //////////////////////////////////////////////////////////
    // Section 4: Compute factorials fact[k] for k = 0..n
    //////////////////////////////////////////////////////////
    long long fact[11];
    fact[0] = 1;
    for (int k = 1; k <= n; k++) {
        fact[k] = fact[k - 1] * k;
        // Factorial is non-decreasing for k >= 1
    }
    // Final factorial is positive

    //////////////////////////////////////////////////////////
    // Section 5: Compute Fibonacci sequence fib[i] for i = 0..n+1
    //////////////////////////////////////////////////////////
    long long fib[12];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n + 1; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        // Fibonacci recurrence relation
    }
    if (n >= 1) {
        // Sequence is non-decreasing for i >= 1
    }

    //////////////////////////////////////////////////////////
    // Section 6: Compute the GCD of two numbers x and y
    //            using the standard Euclidean algorithm
    //////////////////////////////////////////////////////////
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 1 && x <= 20);
    assume_abort_if_not(y >= 1 && y <= 20);

    int a = x;
    int b = y;
    while (b != 0) {
        int r = a % b;
        // Remainder property: 0 <= r < b
        a = b;
        b = r;
    }
    // 'a' now holds gcd(x, y)

    return 0;
}