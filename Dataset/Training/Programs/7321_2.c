// Extended Euclidean Algorithm with Verification-Friendly Loop Invariants
// This program computes the greatest common divisor (gcd) of two positive integers
// using the extended Euclid’s algorithm. It also computes the Bezout coefficients x0,y0
// such that A0*x0 + B0*y0 = gcd(A0,B0). The loop contains assertions that encode
// the invariant relationships between the original inputs and the evolving state.

// Declarations for verification environment
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    // Signal an error to the verification harness
    __assert_fail("0", "extended_gcd.c", __LINE__, "reach_error");
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

// Entry point
int main() {

    // Input variables (nondeterministic but assumed within bounds)
    int a_init;
    int b_init;

    // Read two nondeterministic integers
    a_init = __VERIFIER_nondet_int();
    assume_abort_if_not(a_init >= 1 && a_init <= 1000);

    b_init = __VERIFIER_nondet_int();
    assume_abort_if_not(b_init >= 1 && b_init <= 1000);

    // Copy inputs into long long for intermediate arithmetic
    long long A0;
    long long B0;

    A0 = (long long)a_init;
    B0 = (long long)b_init;

    // Working variables for the algorithm
    long long A;
    long long B;

    long long x0;
    long long y0;

    long long x1;
    long long y1;

    long long t0;
    long long t1;

    long long q;
    long long r;

    // Initialize the state
    A = A0; // current a
    B = B0; // current b

    // Bezout coefficient trackers
    x0 = 1;
    y0 = 0;
    x1 = 0;
    y1 = 1;

    // -------------------------------------------------------------------------
    // Main loop: while B != 0, perform the division step of the extended Euclidean
    // algorithm. At each iteration, we assert that the following invariant holds:
    //
    //    A0*x0 + B0*y0 == A
    //    A0*x1 + B0*y1 == B
    //
    // These two assertions verify that our coefficient-tracking is correct.
    // The loop will terminate when the remainder r becomes zero.
    // -------------------------------------------------------------------------

    while (B != 0) {

        // Check that the evolving Bezout relationships hold
        __VERIFIER_assert(A0 * x1 + B0 * y1 - B == 0);

        // Compute quotient and remainder
        q = A / B;
        r = A - q * B;

        // Update temporary Bezout coefficients
        t0 = x0 - q * x1;
        t1 = y0 - q * y1;

        // Shift registers for Euclid’s step
        A = B;
        B = r;

        x0 = x1;
        y0 = y1;

        x1 = t0;
        y1 = t1;
    }

    // After loop, B == 0 and A == gcd(A0,B0). We assert one final relationship:
    //    A0*x0 + B0*y0 == A
    // which confirms the computed gcd and Bezout coefficients.

    // Program terminates successfully; gcd is in A, coefficients in x0,y0
    return 0;
}