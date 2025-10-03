#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "myprogram.c", 3, "reach_error"); }

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
    int a, b, c;
    int sum = 0, product = 1;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    c = __VERIFIER_nondet_int();
    assume_abort_if_not(c > 0 && c <= 10);

    int counter = 0;
    while (counter < c) {
        int temp = __VERIFIER_nondet_int();
        assume_abort_if_not(temp >= 0);
        sum += temp;
        product *= (temp + 1);
        counter++;
    }

    __VERIFIER_assert(sum >= 0 && product > 0);

    // Another logical relationship to verify
    if (a + b > sum) {
    }

    return 0;
}