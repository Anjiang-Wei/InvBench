#include <stddef.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "int_sqrt.c", 7, "reach_error");
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

int main() {
    int N0 = __VERIFIER_nondet_int();
    /* restrict N0 so that tools can fully unroll the loop */
    assume_abort_if_not(N0 >= 0 && N0 <= 1000);

    long long N = N0;
    long long r = 0;
    int counter = 0;

    /* find the integer square root: largest r with r*r <= N */
    while ((r + 1) * (r + 1) <= N && counter < 1000) {
        r++;
        counter++;
    }

    /* check correctness: r*r <= N < (r+1)*(r+1) */
    __VERIFIER_assert(r * r <= N && (r + 1) * (r + 1) > N);

    return 0;
}