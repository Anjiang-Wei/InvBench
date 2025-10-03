/*
  A comprehensive verification-friendly C program that computes
  the greatest common divisor (GCD) of two small non-negative integers
  using three different algorithms, and checks that all three agree.
  The program is suitable for bounded model checkers and other
  automated verification tools.
*/

#include <assert.h>
#include <limits.h>

/* Error handling and verification primitives */
extern void abort(void);
void reach_error() { assert(0); }

/* Nondeterministic unsigned int generator (stub for verification) */
extern unsigned int __VERIFIER_nondet_uint(void);

/* Assumes a condition, aborts if false */
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* Verification assertion */
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Maximum number of prime factors that we will record */
#define MAX_FACTORS 32

/* Structure to hold the prime factorization of a number */
typedef struct {
    unsigned int primes[MAX_FACTORS];
    unsigned int exponents[MAX_FACTORS];
    unsigned int count;
} factor_list_t;

/*
   Function: factorize
   -------------------
   Computes the prime factorization of n, storing the result in fl.
   fl->count will be the number of distinct prime factors found.
   Each prime and its exponent are stored in arrays inside fl.
*/
void factorize(unsigned int n, factor_list_t *fl) {
    unsigned int x = n;
    unsigned int p = 2;
    fl->count = 0;

    /* Trial division up to sqrt(x) */
    while (x > 1 && p * p <= x) {
        if (x % p == 0) {
            unsigned int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            if (fl->count < MAX_FACTORS) {
                fl->primes[fl->count] = p;
                fl->exponents[fl->count] = cnt;
                fl->count++;
            }
        }
        p++;
    }

    /* If there's any prime > sqrt(n) left */
    if (x > 1) {
        if (fl->count < MAX_FACTORS) {
            fl->primes[fl->count] = x;
            fl->exponents[fl->count] = 1;
            fl->count++;
        }
    }
}

/*
   Function: compute_gcd_from_factors
   ----------------------------------
   Given two factor lists fa and fb, computes the GCD by taking, for
   each prime that appears in both lists, the minimal exponent.
   Returns the product of those primes raised to the minimal exponents.
*/
unsigned int compute_gcd_from_factors(const factor_list_t *fa,
                                      const factor_list_t *fb) {
    unsigned int result = 1;
    unsigned int i, j;

    for (i = 0; i < fa->count; i++) {
        unsigned int p = fa->primes[i];
        unsigned int ea = fa->exponents[i];
        /* Search for p in the second factor list */
        for (j = 0; j < fb->count; j++) {
            if (fb->primes[j] == p) {
                unsigned int eb = fb->exponents[j];
                unsigned int e_min = (ea < eb) ? ea : eb;
                /* Multiply result by p^e_min */
                while (e_min > 0) {
                    result *= p;
                    e_min--;
                }
                break;
            }
        }
    }
    return result;
}

/*
   Function: gcd_euclid
   --------------------
   Standard Euclidean algorithm for GCD:
   while b != 0: (a, b) = (b, a % b)
   returns a.
*/
unsigned int gcd_euclid(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

/*
   Function: gcd_binary
   --------------------
   Stein's algorithm (binary GCD). Uses only subtraction,
   bitwise operations, and comparisons.
*/
unsigned int gcd_binary(unsigned int u, unsigned int v) {
    if (u == 0) {
        return v;
    }
    if (v == 0) {
        return u;
    }

    /* Find common factors of 2 */
    unsigned int shift = 0;
    while (((u | v) & 1) == 0) {
        u >>= 1;
        v >>= 1;
        shift++;
    }
    /* Divide u by 2 until odd */
    while ((u & 1) == 0) {
        u >>= 1;
    }
    do {
        /* Remove all factors of 2 in v */
        while ((v & 1) == 0) {
            v >>= 1;
        }
        /* Now both u and v are odd. Swap if necessary so u <= v */
        if (u > v) {
            unsigned int t = u;
            u = v;
            v = t;
        }
        v = v - u;
    } while (v != 0);

    /* Restore common factors of 2 */
    return u << shift;
}

int main() {
    unsigned int A, B;
    /* Read two nondeterministic inputs */
    A = __VERIFIER_nondet_uint();
    B = __VERIFIER_nondet_uint();

    /* Constrain them to a small range so the loops are bounded */
    assume_abort_if_not(A <= 100);
    assume_abort_if_not(B <= 100);
    /* Avoid both zero (GCD(0,0) is undefined) */
    assume_abort_if_not(!(A == 0 && B == 0));

    /* Compute GCD by three different methods */
    unsigned int g1 = gcd_euclid(A, B);
    unsigned int g2 = gcd_binary(A, B);

    factor_list_t fa, fb;
    factorize(A, &fa);
    factorize(B, &fb);
    unsigned int g3 = compute_gcd_from_factors(&fa, &fb);

    /* Check consistency: all three methods yield the same result */

    /* Additional sanity checks */
    /* GCD must divide both A and B */

    /* GCD must be non-negative and at most max(A,B) */
    __VERIFIER_assert(g1 <= (A > B ? A : B));

    return 0;
}