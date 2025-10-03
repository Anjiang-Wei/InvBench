#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-program.c", 3, "reach_error"); }
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
    int a, b, m;
    long long sum, prod, c;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 50);
    assume_abort_if_not(b >= 0 && b <= 50);
    assume_abort_if_not(m > 0 && m <= 100);

    sum = 0;
    prod = 1;
    c = 0;

    while (1) {
        if (!(c < m)) {
            break;
        }

        sum = sum + a;
        prod = prod * b;
        c = c + 1;
    }

    // Verify that the computations conform to some constraints
    __VERIFIER_assert(c < m + 1);

    printf("Final Sum: %lld, Product: %lld\n", sum, prod);
    return 0;
}