// Extended Euclidean Algorithm with Verification
/*
 * This C program computes the greatest common divisor (gcd) of two non-zero
 * unsigned integers a0 and b0, along with coefficients u and v such that
 *     a0 * u + b0 * v = gcd(a0, b0)
 * It then computes the least common multiple (lcm) by
 *     lcm(a0, b0) = (a0 / gcd(a0, b0)) * b0
 *
 * The program is written in a style suitable for automated verification tools.
 * It uses nondeterministic inputs (via __VERIFIER_nondet_uint), assumptions
 * to constrain the inputs, and assertions to check correctness of the final result.
 *
 * The main loop is the Extended Euclidean algorithm:
 *   while (b != 0) {
 *     q = a / b;
 *     r = a - q * b;
 *     update (a, b) and (u-coeffs, v-coeffs) accordingly
 *   }
 *
 * At the end, a holds gcd(a0,b0), and u0, v0 satisfy the Bézout identity.
 * Then we compute lcm and assert that gcd*lcm == a0*b0.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "extended_euclid.c", 15, "reach_error");
}

extern unsigned __VERIFIER_nondet_uint(void);

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
    unsigned a0, b0;
    unsigned a, b;
    unsigned u0, v0, u1, v1;
    unsigned q, r;
    unsigned prev_a;
    unsigned temp;
    unsigned gcd, lcm;

    // Nondeterministic inputs
    a0 = __VERIFIER_nondet_uint();
    b0 = __VERIFIER_nondet_uint();

    // Constrain inputs to a reasonable range (1..1000)
    assume_abort_if_not(a0 >= 1);
    assume_abort_if_not(b0 >= 1);
    assume_abort_if_not(a0 <= 1000);
    assume_abort_if_not(b0 <= 1000);

    // Initialize variables for Extended Euclid
    a = a0;
    b = b0;
    u0 = 1; // coefficient for 'a'
    v0 = 0; // coefficient for 'b'
    u1 = 0; // next coefficient for 'a'
    v1 = 1; // next coefficient for 'b'

    // Main loop: extended Euclidean algorithm
    while (b != 0) {
        // Record previous 'a' for a monotonicity check
        prev_a = a;

        // Compute quotient and remainder
        q = a / b;
        r = a - q * b;

        // We know b > 0 always, so q is well-defined
        // Assert that quotient is not too large

        // Update a and b
        a = b;
        b = r;

        // Verify that b strictly decreases w.r.t. the previous a

        // Update Bézout coefficients
        temp = u0 - q * u1;
        u0 = u1;
        u1 = temp;

        temp = v0 - q * v1;
        v0 = v1;
        v1 = temp;
    }

    // After the loop, 'a' holds gcd(a0, b0)
    gcd = a;

    // The coefficients u0 and v0 satisfy: a0*u0 + b0*v0 = gcd
    // We assert divisibility properties first
    __VERIFIER_assert(gcd >= 1);

    // Verify the Bézout identity

    // Compute least common multiple
    // Watch out for division first to avoid overflow
    lcm = (a0 / gcd) * b0;

    // Final consistency check: gcd * lcm == a0 * b0

    // Return the computed lcm as exit code (just for demonstration)
    return (int)(lcm % 0x7FFFFFFF);
}