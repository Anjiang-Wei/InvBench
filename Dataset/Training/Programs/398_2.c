#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 8, "reach_error"); }
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
    int n, m, i, j, sum1, sum2;
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && m >= 0 && n <= 100 && m <= 100);

    int array1[100];
    int array2[100];

    sum1 = 0;
    sum2 = 0;

    for (i = 0; i < n; i++) {
        array1[i] = i;
        sum1 += array1[i];
    }

    for (j = 0; j < m; j++) {
        array2[j] = j * 2;
        sum2 += array2[j];
    }

    // Verification conditions
    __VERIFIER_assert(sum2 == (m * (m - 1)));

    return 0;
}