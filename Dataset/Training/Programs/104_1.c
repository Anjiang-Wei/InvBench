#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }
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

int power(int base, int exp) {
    int result = 1;
    for (; exp > 0; --exp) {
        result *= base;
    }
    return result;
}

int compute_polynomial(int x) {
    // Example polynomial: 3x^4 - 2x^3 + 5x^2 - x + 6
    return 3 * power(x, 4) - 2 * power(x, 3) + 5 * power(x, 2) - x + 6;
}

int main() {
    int x, result;
    x = __VERIFIER_nondet_int();

    // Constraint: x is in the range of -10 to 10
    assume_abort_if_not(x >= -10 && x <= 10);

    result = compute_polynomial(x);

    // A simple check for specific polynomial value
    if (x == 1) {
        __VERIFIER_assert(result == 11);
    } else if (x == -1) {
    } else {
        assume_abort_if_not(result <= 10000 && result >= -10000);
    }

    return 0;
}