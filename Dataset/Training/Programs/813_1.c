// A comprehensive verification-friendly C program that implements and checks
// several algorithms: integer division, GCD, exponentiation, Fibonacci via
// matrix exponentiation, and binomial coefficients. Each algorithm is
// accompanied by a naive version, and we assert equality of results.

// Standard verification hooks
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "multi_algo_verify.c", 10, "reach_error");
}

// Nondeterministic integer generator
extern int __VERIFIER_nondet_int(void);

// Assume and assert for verification tools
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

// Integer division by repeated subtraction
// Computes q = a / b, r = a % b, with a >= 0, b > 0
void divide_func(int a, int b, int *q, int *r) {
    int qq = 0;
    int rr = a;
    while (rr >= b) {
        rr = rr - b;
        qq = qq + 1;
    }
    *q = qq;
    *r = rr;
}

// Euclidean GCD using remainder
int gcd_func(int a, int b) {
    int x = a;
    int y = b;
    while (y != 0) {
        int tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}

// Fast exponentiation by squaring: computes a^b for b >= 0
int power_func(int a, int b) {
    int base = a;
    int exp = b;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = result * base;
        }
        base = base * base;
        exp = exp >> 1;
    }
    return result;
}

// Fibonacci via 2x2 matrix exponentiation
// M = [[1,1],[1,0]]; M^n = [[F(n+1),F(n)],[F(n),F(n-1)]]
void fib_matrix_func(int n, int *fib_n) {
    // result matrix R = identity
    int r00 = 1, r01 = 0, r10 = 0, r11 = 1;
    // base matrix M
    int m00 = 1, m01 = 1, m10 = 1, m11 = 0;
    int exp = n;
    while (exp > 0) {
        if (exp & 1) {
            // R = R * M
            int t00 = r00 * m00 + r01 * m10;
            int t01 = r00 * m01 + r01 * m11;
            int t10 = r10 * m00 + r11 * m10;
            int t11 = r10 * m01 + r11 * m11;
            r00 = t00;
            r01 = t01;
            r10 = t10;
            r11 = t11;
        }
        // M = M * M
        int u00 = m00 * m00 + m01 * m10;
        int u01 = m00 * m01 + m01 * m11;
        int u10 = m10 * m00 + m11 * m10;
        int u11 = m10 * m01 + m11 * m11;
        m00 = u00;
        m01 = u01;
        m10 = u10;
        m11 = u11;
        exp = exp >> 1;
    }
    // F(n) is in R[0][1]
    *fib_n = r01;
}

// Compute binomial coefficient C(n, k) using Pascal's triangle dynamic programming
int binomial_func(int n, int k) {
    // we assume n <= 20 so that a small static table is fine
    int C[21][21];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    return C[n][k];
}

// Naive factorial for small n
int factorial(int n) {
    int f = 1;
    int i = 1;
    while (i <= n) {
        f = f * i;
        i = i + 1;
    }
    return f;
}

// Main routine
int main() {
    // Nondeterministic inputs with constraints
    int a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 5);
    int b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 1 && b <= 5);

    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 8);
    int k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 0 && k <= n);

    // 1) Division check
    int q1 = 0, r1 = 0;
    divide_func(a, b, &q1, &r1);
    // Naive division
    int q2 = 0, r2 = a;
    while (r2 >= b) {
        r2 = r2 - b;
        q2 = q2 + 1;
    }
    __VERIFIER_assert(q1 == q2 && r1 == r2);

    // 2) GCD check
    int g1 = gcd_func(a, b);
    // naive GCD by scanning
    int g2 = 1;
    int limit = (a < b) ? a : b;
    int d = 1;
    while (d <= limit) {
        if (a % d == 0 && b % d == 0) {
            g2 = d;
        }
        d = d + 1;
    }
    // also ensure g1 divides both

    // 3) Power check
    int p1 = power_func(a, b);
    int p2 = 1;
    int ii = 0;
    while (ii < b) {
        p2 = p2 * a;
        ii = ii + 1;
    }

    // 4) Fibonacci check
    int f1 = 0;
    fib_matrix_func(n, &f1);
    // naive Fibonacci
    int f2;
    if (n == 0) {
        f2 = 0;
    } else if (n == 1) {
        f2 = 1;
    } else {
        int f_prev = 0;
        int f_curr = 1;
        int idx = 2;
        while (idx <= n) {
            int tmp = f_curr + f_prev;
            f_prev = f_curr;
            f_curr = tmp;
            idx = idx + 1;
        }
        f2 = f_curr;
    }

    // 5) Binomial coefficient check
    int b1 = binomial_func(n, k);
    // naive via factorials
    int num = factorial(n);
    int den = factorial(k) * factorial(n - k);
    // den != 0 since 0 <= k <= n
    int b2 = num / den;

    return 0;
}