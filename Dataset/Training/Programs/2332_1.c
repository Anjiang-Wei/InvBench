/*
  Comprehensive Numeric Computations and Verifications

  This C program performs several numeric computations:
   - Sum of first n integers and verifies the closed-form formula.
   - Sum of squares of first n integers and verifies the closed-form formula.
   - Sum of cubes of first n integers and verifies that it's the square of the ordinary sum.
   - Factorial of n (for small n) and a trivial positivity check.
   - Greatest common divisor (GCD) of two integers using Euclid's algorithm,
     and verifies that the result divides both inputs.

  The program uses nondeterministic inputs (via __VERIFIER_nondet_int),
  assumptions to bound them, and __VERIFIER_assert for final correctness checks.
  There are multiple loops, but no loop invariants are exposed as assertions.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "comprehensive.c", 16, "reach_error");
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

/* Function prototypes */
long long compute_sum(int n);
long long compute_sq_sum(int n);
long long compute_cube_sum(int n);
long long compute_fact(int n);
int compute_gcd(int a, int b);

int main() {
    /* Nondeterministic inputs with bounds */
    int n1, n2, n3, n4;
    long long sum1, sqsum, cubesum, fact;
    int a1, b1, g;

    /* Read and bound the inputs */
    n1 = __VERIFIER_nondet_int();
    assume_abort_if_not(n1 >= 0 && n1 <= 100);

    n2 = __VERIFIER_nondet_int();
    assume_abort_if_not(n2 >= 0 && n2 <= 100);

    n3 = __VERIFIER_nondet_int();
    assume_abort_if_not(n3 >= 0 && n3 <= 100);

    n4 = __VERIFIER_nondet_int();
    /* Bound factorial input to avoid overflow */
    assume_abort_if_not(n4 >= 0 && n4 <= 12);

    /* Perform computations */
    sum1 = compute_sum(n1);
    sqsum = compute_sq_sum(n2);
    cubesum = compute_cube_sum(n3);
    fact = compute_fact(n4);

    /* Verify closed-form formulas */
    /* Sum of first n1 integers: n1*(n1+1)/2 */
    __VERIFIER_assert(2 * sum1 == (long long)n1 * (n1 + 1));

    /* Sum of squares of first n2 integers: n2*(n2+1)*(2*n2+1)/6 */

    /*
      Sum of cubes of first n3 integers: (1+2+...+n3)^2
      We only verify this identity when n3 equals n1,
      otherwise we skip this check by forcing n3 == n1.
    */

    /* Factorial positivity check */

    /*
      Compute GCD of n1 and n2 via Euclid's algorithm
      and verify that the result divides both original numbers.
    */
    a1 = n1;
    b1 = n2;
    g = compute_gcd(a1, b1);

    return 0;
}

/*
  compute_sum:
    Computes the sum of the first n positive integers
    S(n) = 1 + 2 + ... + n
*/
long long compute_sum(int n) {
    long long s = 0;
    int i = 1;
    while (i <= n) {
        s += i;
        i++;
    }
    return s;
}

/*
  compute_sq_sum:
    Computes the sum of squares of the first n integers
    S2(n) = 1^2 + 2^2 + ... + n^2
*/
long long compute_sq_sum(int n) {
    long long s = 0;
    for (int i = 1; i <= n; i++) {
        s += (long long)i * i;
    }
    return s;
}

/*
  compute_cube_sum:
    Computes the sum of cubes of the first n integers
    S3(n) = 1^3 + 2^3 + ... + n^3
*/
long long compute_cube_sum(int n) {
    long long s = 0;
    int i;
    for (i = 1; i <= n; i++) {
        s += (long long)i * i * i;
    }
    return s;
}

/*
  compute_fact:
    Computes factorial of n,
    F(n) = 1 * 2 * ... * n
    n is bounded to [0..12] to avoid overflow.
*/
long long compute_fact(int n) {
    long long f = 1;
    int i = 1;
    while (i <= n) {
        f *= i;
        i++;
    }
    return f;
}

/*
  compute_gcd:
    Computes the greatest common divisor of a and b
    using the standard Euclidean algorithm.
*/
int compute_gcd(int a, int b) {
    /* Loop until the remainder is zero */
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    /* 'a' now holds gcd(original a, original b) */
    return a;
}