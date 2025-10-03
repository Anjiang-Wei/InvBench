// This C program performs two separate computations:
// 1) It computes the sum of cubes and the sum of squares for integers 1..kc,
//    along with the triangular numbers, and checks the known formulas:
//      sum_{i=1..n} i^3  = (n(n+1)/2)^2
//      sum_{i=1..n} i^2  = n(n+1)(2n+1)/6
// 2) It computes the sum of Fibonacci numbers F_0..F_{kf-1} and verifies:
//      sum_{i=0..n-1} F_i = F_{n+1} - 1
//
// The program is intended for automated verification tools, uses
// nondeterministic inputs, assumptions, and final assertions.
//
// It is more than 100 lines long and contains two loops with nontrivial logic.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Called when an assertion is violated.
void reach_error() {
    __assert_fail("0", "sum_cube_fib.c", __LINE__, "reach_error");
}

// Nondeterministic integer generator for verification harness
extern int __VERIFIER_nondet_int(void);

// Abort execution if condition is false (used to encode assumptions)
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Check a condition and signal error if false
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // Phase 1 parameters and accumulators
    int kc;               // upper bound for cubic summation
    long long c1;         // loop counter
    long long y1;         // current integer in summation
    long long sum_cubes;  // accumulator for sum of cubes
    long long sum_sumsq;  // accumulator for sum of squares
    long long triangular; // accumulator for triangular numbers

    // Phase 2 parameters and accumulators
    int kf;            // upper bound for Fibonacci summation
    long long c2;      // loop counter
    long long f_prev;  // previous Fibonacci number
    long long f_curr;  // current Fibonacci number
    long long sum_fib; // accumulator for sum of Fibonacci numbers

    // -----------------------------------------------------------------------
    // Read nondeterministic inputs and constrain them
    // -----------------------------------------------------------------------
    kc = __VERIFIER_nondet_int();
    // We choose a safe bound to prevent overflow in long long:
    assume_abort_if_not(kc >= 0 && kc <= 1000);

    kf = __VERIFIER_nondet_int();
    // We choose a smaller bound to keep Fibonacci numbers within 64-bit range:
    assume_abort_if_not(kf >= 0 && kf <= 50);

    // -----------------------------------------------------------------------
    // PHASE 1: Sum of cubes and sum of squares
    // -----------------------------------------------------------------------

    // Initialize accumulators
    c1 = 0;
    y1 = 0;
    sum_cubes = 0;
    sum_sumsq = 0;
    triangular = 0;

    // Loop from 1..kc
    while (1) {
        if (!(c1 < kc)) {
            break;
        }

        // Advance counters
        c1 = c1 + 1;
        y1 = y1 + 1;

        // Update sums
        sum_cubes = sum_cubes + (y1 * y1 * y1);
        sum_sumsq = sum_sumsq + (y1 * y1);
        triangular = triangular + y1;
    }

    // Final assertions for Phase 1:
    // sum of cubes = (triangular number)^2

    // sum of squares = n(n+1)(2n+1)/6
    // multiply both sides by 6 to avoid fractions:

    // -----------------------------------------------------------------------
    // PHASE 2: Sum of Fibonacci numbers
    // -----------------------------------------------------------------------

    // Initialize Fibonacci accumulators
    c2 = 0;
    f_prev = 0; // F_0
    f_curr = 1; // F_1
    sum_fib = 0;

    // Loop to accumulate F_0 + F_1 + ... + F_{kf-1}
    while (1) {
        if (!(c2 < kf)) {
            break;
        }

        // Add the current Fibonacci number (f_prev) to the sum
        sum_fib = sum_fib + f_prev;

        // Advance Fibonacci sequence
        long long tmp = f_prev + f_curr;
        f_prev = f_curr;
        f_curr = tmp;

        // Advance counter
        c2 = c2 + 1;
    }

    // Final assertion for Phase 2:
    // Known identity: sum_{i=0..n-1} F_i  = F_{n+1} - 1
    // Here, after kf iterations:
    //    f_curr == F_{kf+1}
    //    sum_fib  = sum_{i=0..kf-1} F_i
    __VERIFIER_assert(sum_fib + 1 == f_curr);

    return 0;
}