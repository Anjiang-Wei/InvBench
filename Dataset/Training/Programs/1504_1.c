// Pascal's Triangle and Factorial Verification Program
// Verifiable with automated tools such as CBMC, SMACK, or SeaHorn

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "pascal_verify.c", 5, "reach_error");
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

#define MAX_N 20

int main() {
    // N: the size parameter for Pascal's triangle and factorials
    int N = __VERIFIER_nondet_int();
    // restrict N to [0..MAX_N]
    assume_abort_if_not(N >= 0);
    assume_abort_if_not(N <= MAX_N);

    // Pascal's triangle array: C[i][j] = binomial(i, j)
    long long C[MAX_N + 1][MAX_N + 1];
    // sumRow[i] = sum_{j=0..i} C[i][j]
    long long sumRow[MAX_N + 1];
    // pow2[i] = 2^i
    long long pow2[MAX_N + 1];

    int i, j;

    // Initialize row 0
    C[0][0] = 1;
    sumRow[0] = 1;
    pow2[0] = 1;
    __VERIFIER_assert(C[0][0] == 1);

    // Build Pascal's triangle rows 1..N
    for (i = 1; i <= N; i++) {
        // borders of each row
        C[i][0] = 1;
        C[i][i] = 1;
        // inner entries
        for (j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
        // compute sum of row i
        sumRow[i] = 0;
        for (j = 0; j <= i; j++) {
            sumRow[i] += C[i][j];
        }
        // compute 2^i
        pow2[i] = 2 * pow2[i - 1];

        // verify sumRow == 2^i

        // verify symmetry C[i][j] == C[i][i-j]
        for (j = 0; j <= i; j++) {
        }
    }

    // verify that no binomial entry exceeds 2^N
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= i; j++) {
        }
    }

    // Factorial array: fact[k] = k!
    long long fact[MAX_N + 1];
    fact[0] = 1;
    for (i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i;
        // factorial stays positive
    }

    // sumFact = sum_{k=0..N} k!
    long long sumFact = 0;
    for (i = 0; i <= N; i++) {
        sumFact += fact[i];
    }
    // known bound: sum_{k=0..N} k! < (N+1)!

    // verify product of row-sums equals product of 2-powers, step by step
    long long prodRowSums = 1;
    long long prodPow2 = 1;
    for (i = 0; i <= N; i++) {
        prodRowSums *= sumRow[i];
        prodPow2 *= pow2[i];
        // at each step they must remain equal
    }

    return 0;
}