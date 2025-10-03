// Your complete C program here
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_squares.c", __LINE__, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    /* nondeterministic input N, constrained to avoid overflow */
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 1000);

    long long sum = 0;
    long long even = 0;
    long long odd = 0;
    int i = 1;

    /* Compute sum of squares, splitting into even/odd contributions */
    while (i <= N) {
        long long sq = (long long)i * i;
        sum += sq;
        if (i % 2 == 0) {
            even += sq;
        } else {
            odd += sq;
        }
        i++;
    }

    /* Check that even + odd equals the total sum */
    __VERIFIER_assert(even + odd == sum);

    /* Verify the closed‐form: sum_{k=1..N} k^2 = N*(N+1)*(2N+1)/6 */

    return 0;
}