#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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
    int m, n, i, j, sum1, sum2;
    m = __VERIFIER_nondet_int();
    assume_abort_if_not(m > 0 && m <= 10);
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 10);

    i = 0;
    j = 0;
    sum1 = 0;
    sum2 = 0;

    while (i < m) {
        sum1 += i;
        i++;
    }

    while (j < n) {
        sum2 += j * j;
        j++;
    }

    // Verify that both sums are less than a certain threshold
    int threshold = 50;
    __VERIFIER_assert(sum1 < threshold);

    printf("Sum of first series: %d\n", sum1);
    printf("Sum of squares in second series: %d\n", sum2);

    return 0;
}