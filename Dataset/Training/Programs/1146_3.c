/* Hypothetical program calculating a specific sequence of numbers */

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sequence-ll.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int m, n;
    long long a, b, c, sum;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m >= 0 && m <= 10);
    assume_abort_if_not(n >= 0 && n <= 10);

    a = 0;
    b = 0;
    c = 0;
    sum = 0;

    while (1) {
        if (!(sum < m * n)) {
            break;
        }

        a = a + 1;
        b = b + 2;
        c = c + 3;
        sum = a + b + c;
    }

    __VERIFIER_assert(c >= 0);

    printf("Final values are: a = %lld, b = %lld, c = %lld\n", a, b, c);
    return 0;
}