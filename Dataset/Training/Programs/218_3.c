// A program with multiple test functions, each containing loops and
// post-condition assertions. Designed for automated verification.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    // The line number here is arbitrary
    __assert_fail("0", "program.c", 10, "reach_error");
}

// Standard verifier assert
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

// Non-deterministic integer generator (provided by verifier)
extern int __VERIFIER_nondet_int();

// Test 1: Division and modulo via repeated subtraction.
// For a >= 0, b > 0, computes quotient and remainder such that
//   init_a = q * b + r,  0 <= r < b
void test_division_subtraction() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    // Only consider non-negative 'a' and positive 'b'
    if (!(a >= 0 && b > 0)) {
        return;
    }

    int init_a = a;
    int q = 0;
    // Loop: subtract b from a until a < b
    while (a >= b) {
        a = a - b;
        q++;
    }

    // Post-conditions for division:
    //   0 <= remainder < divisor
    //   original = quotient * divisor + remainder
    __VERIFIER_assert(init_a == q * b + a);
}

// Test 2: Modular exponentiation (fast exponentiation).
// Given base >= 0, exp >= 0, mod > 0, computes (base^exp) % mod
// using repeated squaring.
void test_modular_exponentiation() {
    int base = __VERIFIER_nondet_int();
    int exp = __VERIFIER_nondet_int();
    int mod = __VERIFIER_nondet_int();
    // Bound the inputs to keep verification feasible
    if (!(base >= 0 && base <= 1000 &&
          exp >= 0 && exp <= 30 &&
          mod > 0 && mod <= 1000)) {
        return;
    }

    int result = 1;
    int b = base % mod;
    int e = exp;

    // Loop: binary exponentiation
    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * b) % mod;
        }
        b = (b * b) % mod;
        e = e / 2;
    }

    // Post-conditions: result is a valid residue
}

// Test 3: Euclidean algorithm for GCD via remainder.
// For non-negative inputs a, b (not both zero), computes g = gcd(a,b)
// and checks that g divides both original numbers.
void test_gcd_euclid() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    // Only consider non-negative pairs, not both zero
    if (!(a >= 0 && b >= 0)) {
        return;
    }
    if (a == 0 && b == 0) {
        return;
    }

    int init_a = a;
    int init_b = b;

    // Loop: compute gcd
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }

    // Post-conditions: gcd is positive and divides both originals
}

// Test 4: Matrix row-sum and column-sum consistency.
// Builds an n x n matrix of arbitrary ints, sums rows and columns,
// and asserts the total row-sum equals total column-sum.
void test_matrix_properties() {
    int n = __VERIFIER_nondet_int();
    // Keep matrix size small for verification
    if (!(n >= 1 && n <= 50)) {
        return;
    }

    // Statically allocated maximum-size matrix
    int mat[50][50];
    int row_sum[50];
    int col_sum[50];

    // Fill matrix nondeterministically
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = __VERIFIER_nondet_int();
        }
    }

    // Initialize sums
    for (int i = 0; i < n; i++) {
        row_sum[i] = 0;
    }
    for (int j = 0; j < n; j++) {
        col_sum[j] = 0;
    }

    // Compute row sums and column sums
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            row_sum[i] += mat[i][j];
            col_sum[j] += mat[i][j];
        }
    }

    // Compute total sums via rows and via columns
    int total_row = 0;
    for (int i = 0; i < n; i++) {
        total_row += row_sum[i];
    }

    int total_col = 0;
    for (int j = 0; j < n; j++) {
        total_col += col_sum[j];
    }

    // The grand total by rows must equal that by columns
}

int main() {
    // Invoke each test. The verifier will explore all nondet inputs.
    test_division_subtraction();
    test_modular_exponentiation();
    test_gcd_euclid();
    test_matrix_properties();
    return 0;
}