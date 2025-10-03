#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    if (!(a > 0 && b > 0 && a <= 10 && b <= 10)) {
        return 0;
    }

    x = 0;
    y = b;

    while (y > 0) {
        x += a;
        y -= 1;
    }

    __VERIFIER_assert(x == a * b);
    return 0;
}