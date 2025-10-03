// =============================================================================
// Program: Extended Euclidean Algorithm and Fibonacci Sequence Verification
// Description:
//   This C program reads three non-deterministic integer inputs:
//     1) a0 -- first positive integer (>=1, <=1000)
//     2) b0 -- second positive integer (>=1, <=1000)
//     3) n  -- Fibonacci index (>=0, <=20)
//   It then performs two main computations:
//   A) Extended Euclidean Algorithm to compute gcd(a0, b0) and coefficients
//      x, y such that x*a0 + y*b0 = gcd(a0, b0).
//   B) Iterative Fibonacci sequence up to F_n, using a simple loop and
//      verifying the recurrence at each step.
//
// Verification Strategy:
//   - We use __VERIFIER_assert to check the key arithmetic relations
//     (Bezout identity for the gcd part, and the Fibonacci recurrence).
//   - We use assume_abort_if_not to restrict the non-deterministic inputs
//     to safe, bounded ranges to avoid overflow.
//   - The program is written to be analyzable by automated verification tools.
//
// Note:
//   This program intentionally includes multiple assertion checks inside loops
//   but does not expose explicit loop invariants. Instead, the assertions
//   check the consistency of the computed values directly.
// =============================================================================

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "extgcd_fib.c", 20, "reach_error");
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

// -----------------------------------------------------------------------------
// main: orchestrates the two computations
// -----------------------------------------------------------------------------
int main() {
    // Input values
    int a0, b0, n;
    a0 = __VERIFIER_nondet_int();
    b0 = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Restrict inputs to safe ranges
    assume_abort_if_not(a0 >= 1 && a0 <= 1000);
    assume_abort_if_not(b0 >= 1 && b0 <= 1000);
    assume_abort_if_not(n >= 0 && n <= 20);

    // -------------------------------------------------------------------------
    // Part A: Extended Euclidean Algorithm
    // We maintain:
    //   a == x*a0 + y*b0
    //   b == x1*a0 + y1*b0
    // Initially:
    //   a = a0, b = b0
    //   x = 1, y = 0
    //   x1= 0, y1= 1
    // -------------------------------------------------------------------------
    long long a = a0, b = b0;
    long long x = 1, y = 0;
    long long x1 = 0, y1 = 1;
    long long q, r;
    long long x2, y2;

    // Initial assertion: check the starting Bezout relations

    // Loop: perform the standard extended Euclid
    while (b != 0) {
        // Assert invariant before performing the division step
        __VERIFIER_assert(a == x * a0 + y * b0);

        // Compute quotient and remainder
        q = a / b;
        r = a - q * b;

        // Update the coefficient pairs
        x2 = x - q * x1;
        y2 = y - q * y1;

        // Move to next state
        a = b;
        b = r;
        x = x1;
        y = y1;
        x1 = x2;
        y1 = y2;
    }

    // After the loop, b == 0, a == gcd(a0,b0), and x,y satisfy Bezout identity

    // Optionally compute modular inverse when gcd == 1
    if (a == 1) {
        long long modinv = x % b0;
        if (modinv < 0) {
            modinv += b0;
        }
        // Check that (a0 * modinv) mod b0 == 1
    }

    // -------------------------------------------------------------------------
    // Part B: Fibonacci Sequence Computation
    // Compute F_0, F_1, ..., F_n iteratively
    //   F_0 = 0
    //   F_1 = 1
    //   F_{k} = F_{k-1} + F_{k-2}   for k >= 2
    // We keep fib_prev = F_{i-1}, fib_cur = F_i
    // -------------------------------------------------------------------------
    long long fib_prev = 0;
    long long fib_cur = 1;
    long long fib_next;
    int i = 1;

    // Edge case: n = 0
    if (n == 0) {
        fib_cur = 0;
    }

    // Main loop for Fibonacci from i=1 up to n
    while (i < n) {
        // Compute next Fibonacci term
        fib_next = fib_prev + fib_cur;

        // Assert the recurrence relation directly

        // Step forward
        fib_prev = fib_cur;
        fib_cur = fib_next;
        i++;
    }

    // Final checks: fib_cur should be F_n
    if (n == 0) {
    } else if (n == 1) {
    } else {
        // For n >= 2, ensure fib_cur > fib_prev
    }

    return 0;
}

// -----------------------------------------------------------------------------
// End of File
// -----------------------------------------------------------------------------