// A simple factorization program using trial division,
// suitable for automated verification tools.

#include <limits.h>

extern void abort(void);
void reach_error() { abort(); }

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

int main() {
    int n = __VERIFIER_nondet_int();
    // restrict n to a reasonable positive range
    assume_abort_if_not(n >= 2 && n <= 10000);

    int d = 2;
    // find the smallest divisor d > 1, or stop when d*d > n
    while (d * d <= n && n % d != 0) {
        d++;
    }

    // After the loop:
    //   - if d*d > n, then n is prime
    //   - otherwise, d is a non-trivial divisor of n
    int is_prime = (d * d > n);
    __VERIFIER_assert(
        is_prime || (d >= 2 && d < n && n % d == 0));

    return 0;
}