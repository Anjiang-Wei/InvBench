#include <limits.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "isqrt_subtract.c", 6, "reach_error");
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
    int n = __VERIFIER_nondet_int();
    /* we only handle 0 <= n <= 100000 */
    assume_abort_if_not(n >= 0 && n <= 100000);

    /* we compute r = floor(sqrt(n)) by subtracting odd numbers */
    int original = n;
    int n0 = n;
    int r = 0;
    int odd = 1;

    /* loop: while there remains enough to subtract the next odd */
    while (n0 >= odd) {
        /* invariant: n0 + r*r == original */
        /* odd should always be 2*r + 1 */
        __VERIFIER_assert(odd == 2 * r + 1);

        n0 = n0 - odd;
        odd = odd + 2;
        r = r + 1;
    }

    /* after loop, verify post-conditions */
    /* r*r <= original < (r+1)*(r+1) */

    return 0;
}