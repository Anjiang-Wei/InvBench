#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }
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
    int a, b, n;
    long long m, sum, product;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);
    assume_abort_if_not(n >= 1);

    sum = 0;
    product = 1;
    int counter = 0;

    while (counter < n) {
        sum += a + b;
        product *= (a + 1);

        __VERIFIER_assert(product >= 0); // Ensure no integer overflow for positive `a`

        if (sum > 1000) { // Introduce a meaningful constraint
            break;
        }

        counter++;
    }

    m = sum * product;

    // Check if some condition holds true
    return 0;
}