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
    int a, n, m;
    long long factorial, power, b;

    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 10);

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 1 && m <= 10);

    factorial = 1;
    power = 1;
    b = 0;

    int i = 1;

    while (n > 0) {
        factorial *= i++;
        n--;
    }

    while (m > 0) {
        power *= a;
        m--;
    }

    b = factorial + power;

    __VERIFIER_assert(b >= factorial && b >= power); // Ensuring logical condition is verified

    printf("Factorial: %lld, Power: %lld, Sum: %lld\n", factorial, power, b);
    return 0;
}