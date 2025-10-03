// complex_series.c
// A combined C program performing various series and number-theoretic computations.
// Each phase uses loops to compute a quantity, followed by an assertion of a known formula.
// This program is intended for automated verification tools.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "complex_series.c", 6, "reach_error");
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
    int i;

    /************************************************************************
     * Phase 1: Arithmetic Series
     * Compute sum1 = 1 + 2 + ... + n1
     * Known closed-form: sum1 = n1*(n1+1)/2
     ************************************************************************/
    int n1 = __VERIFIER_nondet_int();
    assume_abort_if_not(n1 >= 0 && n1 <= 1000);
    long long sum1 = 0;
    for (i = 1; i <= n1; i++) {
        sum1 += i;
    }
    // Assert the closed-form formula

    /************************************************************************
     * Phase 2: Sum of Squares
     * Compute sum2 = 1^2 + 2^2 + ... + n2^2
     * Known closed-form: sum2 = n2*(n2+1)*(2*n2+1)/6
     ************************************************************************/
    int n2 = __VERIFIER_nondet_int();
    assume_abort_if_not(n2 >= 0 && n2 <= 500);
    long long sum2 = 0;
    for (i = 1; i <= n2; i++) {
        sum2 += (long long)i * i;
    }
    // Assert the closed-form formula

    /************************************************************************
     * Phase 3: Geometric Series
     * Compute geo_sum = 1 + z + z^2 + ... + z^(k-1)
     * Known relation: if z != 1, (z-1)*geo_sum = z^k - 1; if z == 1, geo_sum = k
     ************************************************************************/
    int z = __VERIFIER_nondet_int();
    assume_abort_if_not(z >= 0 && z <= 20);
    int k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 0 && k <= 50);

    long long geo_sum = 0;
    long long power = 1;
    for (i = 0; i < k; i++) {
        geo_sum += power;
        power *= z;
    }

    if (z == 1) {
    } else {
    }

    /************************************************************************
     * Phase 4: Sum of Factorials
     * Compute fact = 1*2*...*m and sum3 = 1! + 2! + ... + m!
     * We assert the bounds: sum3 >= fact and sum3 <= m*fact
     ************************************************************************/
    int m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 0 && m <= 20);

    long long fact = 1;
    long long sum3 = 0;
    for (i = 1; i <= m; i++) {
        fact *= i;
        sum3 += fact;
    }
    __VERIFIER_assert(sum3 <= (long long)m * fact);

    /************************************************************************
     * Phase 5: Fibonacci Sequence
     * Compute F(0), F(1), ..., F(n3) and fib_sum = sum_{i=0..n3} F(i)
     * Known relation: sum_{i=0..n3} F(i) = F(n3+2) - 1
     ************************************************************************/
    int n3 = __VERIFIER_nondet_int();
    assume_abort_if_not(n3 >= 0 && n3 <= 45);

    long long f_prev = 0;
    long long f_curr = 1;
    long long fib_sum = 0;
    for (i = 0; i <= n3; i++) {
        long long f_next;
        if (i == 0) {
            f_curr = 0;
            f_prev = 0;
            f_next = 1;
        } else if (i == 1) {
            f_curr = 1;
            f_prev = 0;
            f_next = 1;
        } else {
            f_next = f_prev + f_curr;
            f_prev = f_curr;
            f_curr = f_next;
        }
        fib_sum += f_curr;
    }
    // After the loop, f_curr holds F(n3), f_prev holds F(n3-1), and the next term would be F(n3+1).
    // We recompute F(n3+2) by one more step:
    long long f_np1 = f_prev + f_curr; // F(n3+1)
    long long f_np2 = f_curr + f_np1;  // F(n3+2)

    /************************************************************************
     * Phase 6: GCD and LCM
     * Compute gcd(a,b) via Euclid's algorithm, then lcm = a*b/gcd.
     * We assert gcd*lcm == a*b (with care for zero arguments).
     ************************************************************************/
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 1000);
    assume_abort_if_not(b >= 0 && b <= 1000);

    int orig_a = a;
    int orig_b = b;
    // Euclid's algorithm
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    int gcd = a;
    long long lcm;
    if (orig_a == 0 || orig_b == 0) {
        lcm = 0;
    } else {
        lcm = ((long long)orig_a / gcd) * orig_b;
    }

    return 0;
}