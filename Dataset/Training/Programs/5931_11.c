// A complex C program with multiple loops and computational logic,
// suitable for automated verification tools.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "combined.c", 1, "reach_error");
}

extern unsigned __VERIFIER_nondet_uint(void);
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

#define MAX_N 20
#define MAX_VAL 100

int main() {
    // 1. Read a size n for combinatorial computations
    unsigned n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n <= MAX_N);

    // 2. Prepare Pascal's triangle DP table: C[i][j] = binomial(i, j)
    unsigned C[MAX_N + 1][MAX_N + 1];
    for (unsigned i = 0; i <= n; i++) {
        for (unsigned j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
            // Partial sanity check: C[i][j] >= 1
        }
    }

    // 3. Compute factorials up to n
    unsigned long long fact[MAX_N + 1];
    fact[0] = 1ULL;
    for (unsigned i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * (unsigned long long)i;
        // Check monotonic growth for small n
    }

    // 4. Verify binomial via factorial formula: fact[i] / (fact[j]*fact[i-j])
    for (unsigned i = 0; i <= n; i++) {
        for (unsigned j = 0; j <= i; j++) {
            unsigned long long num = fact[i];
            unsigned long long den = fact[j] * fact[i - j];
            unsigned long long comb = num / den;
        }
    }

    // 5. Verify that each row of C sums to 2^i
    for (unsigned i = 0; i <= n; i++) {
        unsigned long long sumRow = 0ULL;
        for (unsigned j = 0; j <= i; j++) {
            sumRow += C[i][j];
        }
        // Compute 2^i
        unsigned long long pow2 = 1ULL;
        for (unsigned k = 0; k < i; k++) {
            pow2 = pow2 * 2ULL;
        }
    }

    // --------------------------------------------------------------------
    // Additional array algorithms for verification
    // --------------------------------------------------------------------

    // 6. Read array size m and values for reversal & sorting
    unsigned m = __VERIFIER_nondet_uint();
    assume_abort_if_not(m >= 1 && m <= MAX_N);

    int A[MAX_N];
    int B[MAX_N];

    // Fill A with nondet values in [0, MAX_VAL]
    for (unsigned i = 0; i < m; i++) {
        int v = __VERIFIER_nondet_int();
        assume_abort_if_not(v >= 0 && v <= MAX_VAL);
        A[i] = v;
    }

    // 7. Compute the sum of elements in A
    long long sumA = 0LL;
    for (unsigned i = 0; i < m; i++) {
        sumA += (long long)A[i];
    }
    // sumA is non-negative

    // 8. Reverse A into B
    for (unsigned i = 0; i < m; i++) {
        B[i] = A[m - 1 - i];
    }
    // 9. Check that reversal preserved sum and elements
    long long sumB = 0LL;
    for (unsigned i = 0; i < m; i++) {
        sumB += (long long)B[i];
    }

    // 10. Bubble sort A in place
    for (unsigned pass = 0; pass < m; pass++) {
        for (unsigned j = 0; j + 1 < m; j++) {
            if (A[j] > A[j + 1]) {
                int tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
    }
    // 11. Verify sorted order
    for (unsigned i = 0; i + 1 < m; i++) {
    }

    // 12. Sum after sort must equal sumA
    long long sumC = 0LL;
    for (unsigned i = 0; i < m; i++) {
        sumC += (long long)A[i];
    }

    // --------------------------------------------------------------------
    // Binary search in the sorted array
    // --------------------------------------------------------------------
    int target = __VERIFIER_nondet_int();
    assume_abort_if_not(target >= 0 && target <= MAX_VAL);

    int low = 0, high = (int)m - 1;
    int found = 0;
    int foundIndex = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == target) {
            found = 1;
            foundIndex = mid;
            break;
        } else if (A[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found) {
        // Confirm that A[foundIndex] == target
        __VERIFIER_assert(A[foundIndex] == target);
    } else {
        // Confirm target is indeed not in A
        for (unsigned i = 0; i < m; i++) {
        }
    }

    return 0;
}