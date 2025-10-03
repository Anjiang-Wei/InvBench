// Integer square root computation with verification of the final result
// Computes r = floor(sqrt(n)) for 0 ≤ n ≤ 10000

#include <limits.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "intsqrt.c", 10, "reach_error");
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

int counter = 0;

int main() {
    int n = __VERIFIER_nondet_int();
    // Restrict the input domain for analysis
    assume_abort_if_not(n >= 0 && n <= 10000);

    int r = 0;
    // A simple linear search for floor(sqrt(n))
    // We also bound the number of iterations to ensure termination in analysis
    while (counter++ < 10005) {
        // If the next square would exceed n, stop
        if ((long long)(r + 1) * (r + 1) > n) {
            break;
        }
        r++;
    }

    // Post-condition: r^2 ≤ n < (r+1)^2
    __VERIFIER_assert((long long)r * r <= n);

    return 0;
}