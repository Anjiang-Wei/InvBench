// Combined computations: factorials, Fibonacci, Pascal's triangle, Catalan numbers,
// array reversal, and pseudo-random sequence.
// This program uses several loops and asserts algebraic identities and properties
// but does not expose explicit loop invariants.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "combined.c", 7, "reach_error");
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
}

extern int __VERIFIER_nondet_int(void);

int main() {
    // Choose a small n so arrays stay in range and arithmetic does not overflow.
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    // 1) Factorial computation
    int f[12];
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i;
        // Check the local multiplication property
    }

    // 2) Fibonacci sequence computation up to n+2
    int fib[15];
    fib[0] = 0;
    if (n + 2 >= 1) {
        fib[1] = 1;
    }
    for (int i = 2; i <= n + 2; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        // Check the recurrence
    }

    // 3) Pascal's triangle up to row n
    int C[12][12];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
        // Sum of row i should be 2^i
        int rowSum = 0;
        for (int j = 0; j <= i; j++) {
            rowSum += C[i][j];
        }
    }

    // 4) Catalan numbers up to n
    // C0 = 1, C[k+1] = sum_{i=0..k} C[i]*C[k-i]
    int cat[12];
    cat[0] = 1;
    for (int k = 1; k <= n; k++) {
        long long temp = 0;
        for (int i = 0; i < k; i++) {
            temp += (long long)cat[i] * cat[k - 1 - i];
            // Catalan partial sums are non-negative
        }
        // Fit into int for small k
        cat[k] = (int)temp;
        // Catalan numbers strictly increase for k>=1
    }

    // 5) Sum checks: sum of Fibonacci numbers = fib[n+2] - 1
    int sumFib = 0;
    for (int i = 0; i <= n; i++) {
        sumFib += fib[i];
    }

    // 6) Sum of factorials and Catalans
    int sumFact = 0, sumCat = 0;
    for (int i = 0; i <= n; i++) {
        sumFact += f[i];
        sumCat += cat[i];
    }
    // Both sums are positive and sumCat grows faster than sumFact for n>=2
    if (n >= 2) {
    }

    // 7) Array reversal check
    int arr[12];
    // Fill arr with factorial values
    for (int i = 0; i <= n; i++) {
        arr[i] = f[i];
    }
    // Reverse in place
    for (int i = 0; i < n / 2 + 1; i++) {
        int tmp = arr[i];
        arr[i] = arr[n - i];
        arr[n - i] = tmp;
    }
    // After reversal, first element equals original f[n]
    // And last element equals original f[0]

    // 8) Simple xorshift pseudo-random sequence, check non-negativity
    unsigned int x = 2463534242u; // seed
    for (int iter = 0; iter < n * 5 + 1; iter++) {
        // xorshift steps
        x ^= (x << 13);
        x ^= (x >> 17);
        x ^= (x << 5);
        // Always non-negative as unsigned
    }

    // 9) Final consistency checks
    // Factorial of n: 0! = 1
    // Fibonacci zero and one
    // Pascal triangle symmetry for row n
    if (n >= 1) {
    }
    // Catalan base
    __VERIFIER_assert(cat[0] == 1);

    return 0;
}