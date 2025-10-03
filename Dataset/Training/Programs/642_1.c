/* New C Program with constraints and loop */

#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
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
    int N, x, y, z;
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N < 10);

    x = 0;
    y = 0;
    z = 1;

    while (x < N) {
        y = y + z;
        z = z * 2;
        x = x + 1;
    }

    // The final assertion to check the relationship after the loop
    __VERIFIER_assert(y == (1 << x) - 1);

    return 0;
}