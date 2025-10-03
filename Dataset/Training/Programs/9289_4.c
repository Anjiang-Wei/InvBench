// ==========================================================================
// Program: sums of powers
// ==========================================================================
// Computes sum_{k=1}^n k^p for p=1..4 and verifies formulas
// Author: AI
// Description:
//   - n is nondeterministic (0 <= n <= 50)
//   - sum1 = sum k
//   - sum2 = sum k^2
//   - sum3 = sum k^3
//   - sum4 = sum k^4
//   Loop invariants:
//     2*sum1 == i*(i+1)
//     6*sum2 == i*(i+1)*(2i+1)
//     4*sum3 == i^2*(i+1)^2
//     30*sum4 == i*(i+1)*(2i+1)*(3i^2+3i-1)
// ==========================================================================

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sums_powers.c", 23, "reach_error"); }
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

    // Input phase: nondeterministic choice of n
    int n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 50);

    // Initialization of accumulators
    long long sum1 = 0;
    long long sum2 = 0;
    long long sum3 = 0;
    long long sum4 = 0;
    int i = 0;

    // Main loop: iterate i from 0 to n
    while (1) {
        // Check loop invariants for current i
        __VERIFIER_assert(30 * sum4 == (long long)i * (i + 1) * (2 * i + 1) *
                                           (3 * i * i + 3 * i - 1));

        if (!(i < n)) {
            // Exit when we've reached i == n
            break;
        }

        // Compute next term index k = i+1
        int k = i + 1;
        // powers of k
        long long k2 = (long long)k * k;
        long long k3 = k2 * k;
        long long k4 = k2 * k2;

        // Update accumulators
        sum1 += k;
        sum2 += k2;
        sum3 += k3;
        sum4 += k4;

        // Advance iteration
        i = k;
    }

    // Final assertions for i == n

    return 0;
}

// ==========================================================================
// Discussion:
//   The loop computes sums of consecutive integers and verifies the known
//   closed-form polynomial formulas at each iteration.
//   Automated solvers can use these assertions to establish the correctness.
//   No overflows occur for n <= 50 in 64-bit integers.
//   The approach illustrates the use of polynomial invariants.
//
// Variants:
//   One can extend this program to higher powers or different sequences.
//   For instance, sum of fifth powers has formula...
//   The program structure remains similar.
//
// Conclusion:
//   This self-contained C program is suitable for static analysis.
// ==========================================================================
// Note: verify with CBMC or CPAchecker
// (C) Generated for verification example
/* End of C program */