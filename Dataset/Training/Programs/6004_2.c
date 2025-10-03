#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 4, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int n, factorial, i;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Limiting to 12 to prevent overflow of factorial in int

    factorial = 1;
    i = 1;

    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verify factorial calculation for expected range
    if (n == 0 || n == 1) {
    } else if (n == 2) {
        __VERIFIER_assert(factorial == 2);
    } else if (n == 3) {
    } else if (n == 4) {
    } else if (n == 5) {
    } else if (n == 6) {
    } else if (n == 7) {
    } else if (n == 8) {
    } else if (n == 9) {
    } else if (n == 10) {
    } else if (n == 11) {
    } else if (n == 12) {
    }

    return 0;
}