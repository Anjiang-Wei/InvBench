#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;

    assume_abort_if_not(a > 0 && a < 100);
    assume_abort_if_not(b > 0 && b < 100);

    int i = 0;
    while (i < 10) {
        sum = sum + a;
        if (sum > 1000) {
            break;
        }
        i++;
    }

    // Ensure that the loop completed without accidental overflow
    __VERIFIER_assert(sum <= 1000);

    // Another assertion to ensure some property

    printf("Final sum: %d\n", sum);
    printf("Doubled b: %d\n", b * 2);

    return 0;
}