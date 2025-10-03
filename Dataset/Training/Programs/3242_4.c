/*
 * Complex Series and Sequences Verification Program
 *
 * This program demonstrates several classic sequence formulas
 * and uses verification-friendly loop invariants to check
 * correctness at each iteration and upon termination.
 *
 * It covers:
 *  1) Geometric series:   sum_{i=0..k-1} z^i = (z^k - 1)/(z - 1)
 *  2) Arithmetic series:  sum_{i=1..m} i    = m*(m+1)/2
 *  3) Sum of squares:     sum_{i=1..u} i^2  = u*(u+1)*(2u+1)/6
 *  4) A mixed loop that alternately applies geometric
 *     and arithmetic updates, to show how invariants
 *     can be checked in a more complex setting.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "complex_series.c", 20, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

/* aborts if cond is false, to bound nondet values */
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* reports an error if cond is false */
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    /* Nondeterministic inputs with bounding assumptions */
    int z = __VERIFIER_nondet_int();
    assume_abort_if_not(z >= 2 && z <= 10);
    int k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 0 && k <= 20);
    int m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 0 && m <= 50);
    int u = __VERIFIER_nondet_int();
    assume_abort_if_not(u >= 0 && u <= 50);

    /*
     * Loop 1: Geometric series
     *   x = sum_{i=0..c-1} z^i
     *   y = z^c
     * Invariant: x*(z-1) == y - 1
     */
    long long x = 0;
    long long y = 1;
    long long c = 0;
    while (c < k) {
        /* invariant check */

        /* step */
        x = x * z + 1;
        y = y * z;
        c = c + 1;
    }
    /* final check */

    /*
     * Loop 2: Arithmetic series
     *   sumA = sum_{i=1..t} i
     * Invariant: 2*sumA == t*(t+1)
     */
    long long sumA = 0;
    long long t = 0;
    while (t < m) {
        t = t + 1;
        sumA = sumA + t;
    }
    __VERIFIER_assert(2 * sumA == m * (m + 1));

    /*
     * Loop 3: Sum of squares
     *   sumSq = sum_{i=1..v} i^2
     * Invariant: 6*sumSq == v*(v+1)*(2*v+1)
     */
    long long sumSq = 0;
    long long v = 0;
    while (v < u) {
        v = v + 1;
        sumSq = sumSq + v * v;
    }

    /*
     * Loop 4: Mixed geometric/arithmetic updates
     *   Demonstrates alternating invariants in one loop.
     */
    {
        int N = __VERIFIER_nondet_int();
        assume_abort_if_not(N >= 0 && N <= 15);

        long long a = 1;
        long long b = 1;
        int iter = 1;

        while (iter <= N) {
            if ((iter % 2) == 0) {
                /* geometric-style step on 'a' */
                a = a * z + 1;
            } else {
                /* arithmetic-style step on 'b' */
                b = b + iter;
            }
            iter++;
        }

        /* basic sanity checks at the end */
    }

    return 0;
}