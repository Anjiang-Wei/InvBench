#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "myprogram.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, m, sum, temp, count;
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);
    assume_abort_if_not(m >= 0 && m <= 20);

    sum = 0;
    count = 0;

    // Loop only when n and m have meaningful values
    while (count++ < 1) {
        if (n > 0) {
            // calculate sum of first n multiples of m
            temp = n;
            while (temp > 0) {
                sum += m * temp;
                temp--;
            }
        }

        if (m > 0) {
            // calculate sum of first m multiples of n
            temp = m;
            while (temp > 0) {
                sum += n * temp;
                temp--;
            }
        }
        break;
    }

    __VERIFIER_assert(sum >= 0); // Ensures the sum doesn't wrap around to negative
    printf("Computed sum: %d\n", sum);
    return 0;
}