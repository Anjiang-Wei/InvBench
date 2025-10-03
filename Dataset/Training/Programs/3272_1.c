#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "derived_program.c", 4, "reach_error"); }
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

extern int __VERIFIER_nondet_int(void);

int main() {
    int counter = 0;
    int a = 0, b = 0, c = 0, limit;
    limit = __VERIFIER_nondet_int();

    assume_abort_if_not(limit > 0);
    assume_abort_if_not(limit < 100);

    while (counter < limit) {
        b = a + 2 * c;
        c = b - a;
        a = c + 1;

        counter++;
        __VERIFIER_assert(b <= a + c);
    }

    printf("Final values: a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}