// mult_sum.c
#include <stddef.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "mult_sum.c", 5, "reach_error");
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
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    /* restrict inputs to a safe small range */
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);

    /* remember originals for checks */
    int orig_a = a;
    int orig_b = b;

    /* compute product = orig_a * orig_b by repeated addition */
    int product = 0;
    int i = 0;
    while (i < orig_b) {
        product += orig_a;
        i++;
    }
    /* check final product */

    /* compute sum of 0..orig_a: sum = orig_a*(orig_a+1)/2 */
    int sum = 0;
    i = 0;
    while (i <= orig_a) {
        sum += i;
        i++;
    }
    /* check final sum formula */
    __VERIFIER_assert(2 * sum == orig_a * (orig_a + 1));

    return 0;
}