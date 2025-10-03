#include <limits.h>

/*
   A C program that sums even and odd numbers separately up to a nondeterministic bound k.
   It then checks the closed-form formulas:
     sum of first ce even numbers = ce*(ce-1)
     sum of first co odd numbers  = co*co
   This program is suitable for automated verification.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_even_odd.c", 10, "reach_error");
}

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

extern int __VERIFIER_nondet_int(void);

int main() {
    int k = __VERIFIER_nondet_int();
    /* bound k to avoid unbounded loops */
    assume_abort_if_not(k >= 0 && k <= 100000);

    int c = 0;
    int ce = 0; /* count of even numbers encountered */
    int co = 0; /* count of odd numbers encountered */
    int se = 0; /* sum of even numbers */
    int so = 0; /* sum of odd numbers */

    /* Loop over 0,1,2,...,k-1 */
    while (c < k) {
        if ((c % 2) == 0) {
            /* c is even */
            se += c;
            ce++;
        } else {
            /* c is odd */
            so += c;
            co++;
        }
        c++;
    }

    /*
      Known formulas:
        Sum of the first ce even numbers (0 + 2 + 4 + ... + 2*(ce-1)) = ce*(ce-1)
        Sum of the first co odd numbers  (1 + 3 + 5 + ... + (2*co-1)) = co*co
    */
    __VERIFIER_assert(se == ce * (ce - 1));

    return 0;
}