#include <assert.h>
#include <stdlib.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sum_squares.c", 7, "reach_error");
}
extern short __VERIFIER_nondet_short(void);
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
    short k = __VERIFIER_nondet_short();
    /* bound k to avoid overflow */
    assume_abort_if_not(k >= 0 && k <= 10000);

    long long i = 0;
    long long s = 0;

    /* We maintain the invariant:
         6 * s == i * (i + 1) * (2*i + 1)
       which is the closed‐form for sum_{j=1..i} j^2.
    */
    while (1) {
        __VERIFIER_assert(6 * s == i * (i + 1) * (2 * i + 1));
        if (!(i < k)) {
            break;
        }
        i = i + 1;
        s = s + i * i;
    }

    /* Final check for i == k */
    return 0;
}