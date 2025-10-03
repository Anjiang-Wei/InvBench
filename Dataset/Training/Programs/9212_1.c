#include <stdio.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int m, n, sum = 0, prod = 1;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m >= 0 && m <= 100);
    assume_abort_if_not(n >= 0 && n <= 100);

    int i;
    for (i = 1; i <= m; i++) {
        sum = sum + i;
    }

    i = 1;
    while (i <= n) {
        prod = prod * i;
        i++;
    }

    // Validate that sum and prod maintain certain relationships
    __VERIFIER_assert(sum >= m);

    printf("Sum of numbers from 1 to %d is: %d\n", m, sum);
    printf("Product of numbers from 1 to %d is: %d\n", n, prod);

    return 0;
}