#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

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

extern int __VERIFIER_nondet_int(void);

int main() {
    int a = 0, b = 0, z = 0;
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    while (a <= n && b <= n) {
        if ((a + b) % 2 == 0) {
            a = a + 2;
        } else {
            b = b + 1;
        }
        z = z + 1;
    }

    __VERIFIER_assert((a + b) % 2 == 0 || b > n);

    printf("Final values: a = %d, b = %d, z = %d\n", a, b, z);
    return 0;
}