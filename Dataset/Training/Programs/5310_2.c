#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void __VERIFIER_assume(int cond) {
    if (!cond) {
        exit(0);
    }
}

int __VERIFIER_nondet_int(void);

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int d = __VERIFIER_nondet_int();

    __VERIFIER_assume(a > 0 && b > 0 && c > 0 && d > 0);

    int product = 1;
    for (int i = 0; i < 10; i++) {
        product *= a;
    }

    int sum = 0;
    while (b > 0) {
        sum += c;
        b--;
        __VERIFIER_assert(sum >= 0);
    }

    for (int j = 0; j < 5; j++) {
        d = d + 2 * __VERIFIER_nondet_int();
    }

    printf("Computation completed.\n");
    return 0;
}