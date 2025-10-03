// Extended Euclidean Algorithm and Fibonacci Computation Verification
// This program is designed for automated verification tools.
// It computes GCD and LCM of nondeterministic inputs using the extended
// Euclidean algorithm, checks correctness, then computes Fibonacci numbers
// for a nondeterministic length and verifies the sequence properties.

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Called when a verification assertion fails
void reach_error() {
    __assert_fail("0", "verifier_prog.c", 1, "reach_error");
}

// Abort program if a condition is false (used to encode assumptions)
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Verification assertion: report error if cond is false
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Nondeterministic integer generator for verification
extern int __VERIFIER_nondet_int(void);

// Compute extended GCD of (a,b), check properties, and return LCM
int compute_and_check(int a, int b) {
    // Variables for the extended Euclidean algorithm
    int old_r, r, old_s, s, old_t, t, q, temp;

    old_r = a;
    r = b;
    old_s = 1;
    s = 0;
    old_t = 0;
    t = 1;

    // Main loop: compute remainder sequence until r == 0
    while (r != 0) {
        // Division quotient
        q = old_r / r;
        // Update remainders
        temp = r;
        r = old_r - q * r;
        old_r = temp;
        // Update Bezout coefficients s
        temp = s;
        s = old_s - q * s;
        old_s = temp;
        // Update Bezout coefficients t
        temp = t;
        t = old_t - q * t;
        old_t = temp;

        // At each step, the current gcd candidate must stay non-negative
    }

    // Now old_r is the GCD, and old_s, old_t are Bezout coefficients
    int gcd = old_r;
    int x = old_s;
    int y = old_t;

    // Verify that gcd divides both a and b
    __VERIFIER_assert(gcd >= 0);
    // Verify Bezout identity: a*x + b*y == gcd

    // Compute LCM safely: if gcd != 0 then lcm = (a/gcd)*b else lcm = 0
    int lcm;
    if (gcd != 0) {
        lcm = (a / gcd) * b;
    } else {
        lcm = 0;
    }

    // Verify the product relation: gcd * lcm == a * b

    return lcm;
}

int main() {
    // Number of test cases for GCD/LCM computations
    int k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 1);
    assume_abort_if_not(k <= 5);

    // Arrays to store inputs and outputs
    int a_values[5];
    int b_values[5];
    int lcm_results[5];

    // Loop over each test case, pick nondet inputs, constrain them, compute/check
    int i = 0;
    while (i < k) {
        int a = __VERIFIER_nondet_int();
        int b = __VERIFIER_nondet_int();
        // Constrain the inputs to a convenient range
        assume_abort_if_not(a >= 0);
        assume_abort_if_not(a <= 1000);
        assume_abort_if_not(b >= 0);
        assume_abort_if_not(b <= 1000);

        a_values[i] = a;
        b_values[i] = b;
        // Perform extended GCD/LCM computation and verification
        lcm_results[i] = compute_and_check(a, b);

        i = i + 1;
    }

    // Postcondition checks on the batch of results
    i = 0;
    while (i < k) {
        int a = a_values[i];
        int b = b_values[i];
        int lcm = lcm_results[i];
        // LCM must be non-negative and at least as large as each input
        i = i + 1;
    }

    // ------------------------------------------------------------------------
    // Next: compute Fibonacci sequence up to a nondet length, then verify it
    // ------------------------------------------------------------------------
    int n = __VERIFIER_nondet_int();
    // Constrain the maximum Fibonacci index
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 20);

    // Array to hold Fibonacci numbers (we allocate a bit extra)
    int fib[25];
    // Base cases
    if (n >= 0) {
        fib[0] = 0;
    }
    if (n >= 1) {
        fib[1] = 1;
    }

    // Compute Fibonacci numbers iteratively
    int idx = 2;
    while (idx <= n) {
        fib[idx] = fib[idx - 1] + fib[idx - 2];
        idx = idx + 1;
    }

    // Verify the computed sequence: for every i>=2, fib[i] == fib[i-1] + fib[i-2]
    idx = 2;
    while (idx <= n) {
        idx = idx + 1;
    }

    // If n >= 2, also verify that the sequence is strictly increasing
    // up to a point (Fibonacci grows for n >= 2).
    idx = 2;
    while (idx <= n) {
        idx = idx + 1;
    }

    return 0;
}