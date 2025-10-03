// This is a self-contained C program suitable for automated verification.
// It performs several integer computations (multiplication via addition,
// integer division via subtraction, factorial, and triangular sums) on
// non-deterministic inputs, with assertions to check consistency of results.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "comp-verif.c", 10, "reach_error");
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
    return;
}

int main() {
    // Number of test cases
    int T, t;

    // Primary inputs for each test: x and y
    int x, y;

    // Variables for multiplication via addition
    int mul_via_add;
    int k;

    // Variables for integer division via repeated subtraction
    int divisor;
    int dividend;
    int quotient;
    int remainder;

    // Variables for factorial computation
    int fact;
    int temp;
    int i;

    // Variables for triangular sum
    int tri;
    int i2;

    // Obtain the number of test cases (bounded to keep loops finite)
    T = __VERIFIER_nondet_int();
    assume_abort_if_not(T >= 1 && T <= 5);

    // Loop over each test case
    for (t = 0; t < T; t++) {

        // --------------------------------------------------------------------
        // 1) Get two non-negative integers x and y (up to 100 each)
        // --------------------------------------------------------------------
        x = __VERIFIER_nondet_int();
        y = __VERIFIER_nondet_int();
        assume_abort_if_not(x >= 0 && x <= 100);
        assume_abort_if_not(y >= 0 && y <= 100);

        // --------------------------------------------------------------------
        // 2) Compute x * y by repeated addition
        //    mul_via_add starts at 0, we add x a total of y times
        // --------------------------------------------------------------------
        mul_via_add = 0;
        k = 0;
        while (k < y) {
            mul_via_add = mul_via_add + x;
            k = k + 1;
            // At each iteration, ensure the partial sum matches x * k
        }
        // After the loop, the result should be x * y

        // --------------------------------------------------------------------
        // 3) Perform integer division of dividend by divisor
        //    divisor chosen nondeterministically, ensure > 0
        //    quotient and remainder satisfy dividend == quotient*divisor + remainder
        // --------------------------------------------------------------------
        divisor = __VERIFIER_nondet_int();
        assume_abort_if_not(divisor > 0 && divisor <= 100);

        dividend = x; // use x as the dividend
        quotient = 0;
        remainder = dividend;

        while (remainder >= divisor) {
            remainder = remainder - divisor;
            quotient = quotient + 1;

            // Remainder must stay non-negative
            // The identity must hold at each subtraction step
        }
        // Final checks after loop termination

        // --------------------------------------------------------------------
        // 4) Compute factorial of x, with x <= 10 to avoid overflow
        //    fact = 1 * 2 * ... * x
        // --------------------------------------------------------------------
        assume_abort_if_not(x <= 10);

        fact = 1;
        i = 1;
        while (i < x) {
            temp = fact;
            // multiply by (i+1)
            fact = fact * (i + 1);
            i = i + 1;

            // check that the factorial step was correct
        }
        // For x == 0 or x == 1, fact should remain 1
        if (x == 0 || x == 1) {
        } else {
            // for larger x, factorial grows positively
        }

        // --------------------------------------------------------------------
        // 5) Compute the triangular sum of y: sum_{j=1..y} j = y*(y+1)/2
        // --------------------------------------------------------------------
        tri = 0;
        i2 = 1;
        while (i2 <= y) {
            tri = tri + i2;

            // At each step, partial sum should satisfy 2*tri == i2*(i2+1)

            i2 = i2 + 1;
        }
        // Final triangular number check
        __VERIFIER_assert(2 * tri == y * (y + 1));
    }

    return 0;
}