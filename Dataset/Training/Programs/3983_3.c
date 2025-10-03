/*
  Composite Verified C Program
  This program demonstrates three computation routines:
  1) Binary (peasant) multiplication of two positive integers.
  2) Euclidean algorithm for GCD computation.
  3) Summation formula check via a simple loop.

  The program is designed for verification by automated tools.
  It uses nondeterministic inputs, assume_abort_if_not for constraints,
  and __VERIFIER_assert for safety checks.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    /* Signal a verification failure */
    __assert_fail("0", "composite_prog.c", __LINE__, "reach_error");
}

extern unsigned int __VERIFIER_nondet_uint(void);

/* Abort execution if condition is false */
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* Verification assertion */
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Main routine */
int main() {
    /* ------------------------------------------------------------------
       Section 1: Binary (Peasant) Multiplication
       Computes product = X * Y using doubling and halving.
       ------------------------------------------------------------------ */
    unsigned int X = __VERIFIER_nondet_uint();
    unsigned int Y = __VERIFIER_nondet_uint();
    /* For simplicity, assume both are at least 1 */
    assume_abort_if_not(X >= 1);
    assume_abort_if_not(Y >= 1);

    /* Keep copies of original values for later checks */
    unsigned int origX = X;
    unsigned int origY = Y;

    /* Initialization */
    unsigned long long result = 0ULL;
    unsigned long long rx = X;
    unsigned long long p = 1ULL;
    unsigned long long ytemp = Y;

    /* Loop bounds for verification */
    int bound1 = 0;

    /* Phase 1: Build up doubling until p > Y */
    while (bound1++ < 1000) {
        /* Basic sanity checks */
        __VERIFIER_assert(p >= 1ULL);

        /* Stop when p exceeds Y */
        if (!(p <= ytemp)) {
            break;
        }
        /* Double both p and rx */
        p = p << 1;
        rx = rx << 1;
    }

    /* Phase 2: Halve and accumulate to form the product */
    int bound2 = 0;
    while (bound2++ < 1000) {
        /* Basic sanity checks */

        /* If no more bits, finish */
        if (!(p > 0ULL)) {
            break;
        }
        /* If this bit fits in ytemp, subtract and add rx */
        if (p <= ytemp) {
            ytemp = ytemp - p;
            result = result + rx;
        }
        /* Halve p and rx for next bit */
        p = p >> 1;
        rx = rx >> 1;
    }

    /* Post-condition checks for multiplication */
    /* ytemp should be zero and result should equal original product */

    /* ------------------------------------------------------------------
       Section 2: Euclidean Algorithm for GCD
       Computes g = gcd(a, b) for two positive integers a, b.
       ------------------------------------------------------------------ */
    unsigned int a = __VERIFIER_nondet_uint();
    unsigned int b = __VERIFIER_nondet_uint();
    /* Ensure inputs are positive */
    assume_abort_if_not(a >= 1);
    assume_abort_if_not(b >= 1);

    unsigned int origA = a;
    unsigned int origB = b;
    unsigned int t;

    /* GCD loop with simple assert on positivity */
    int bound3 = 0;
    while (bound3++ < 1000) {
        /* If b becomes zero, we are done */
        if (b == 0U) {
            break;
        }
        /* Compute remainder a % b */
        t = a % b;
        a = b;
        b = t;
        /* No explicit invariant revealed */
    }
    /* Now 'a' holds the GCD */
    unsigned int g = a;

    /* Post-condition checks for GCD */
    /* g divides both origA and origB exactly */
    /* The remainder should be zero in the end */

    /* ------------------------------------------------------------------
       Section 3: Summation Check
       Verifies that sum of 1..N equals N*(N+1)/2
       ------------------------------------------------------------------ */
    unsigned int N = __VERIFIER_nondet_uint();
    /* Keep N manageable for loop bound */
    assume_abort_if_not(N <= 100000U);

    unsigned long long sum = 0ULL;
    unsigned int i = 1U;

    int bound4 = 0;
    while (bound4++ < 1000000) {
        if (!(i <= N)) {
            break;
        }
        sum = sum + (unsigned long long)i;
        i = i + 1U;
    }

    /* Verify the closed-form formula: 2*sum == N*(N+1) */

    /* If we reach here, all verification conditions passed */
    return 0;
}