#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "verifier_example.c", 6, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);

    int i = 0;
    int sum = 0;
    int product = 1;

    // Loop to calculate sum and product of first n integers
    while (i <= n) {

        sum += i;
        if (i > 0) {
            product *= i;
        }

        i++;
    }

    // Post-conditions
    if (n > 0) {
        int expected_product = 1;
        for (int j = 1; j <= n; j++) {
            expected_product *= j;
        }
    } else {
        __VERIFIER_assert(product == 1); // product of zero numbers is considered 1
    }

    return 0;
}