#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_verification.c", 3, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a = 0, b = 0, x, y;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    // Constraints ensuring that x and y have valid values
    assume_abort_if_not(x >= 0 && x <= 1000);
    assume_abort_if_not(y >= 0 && y <= 1000);

    int target = x + y;
    int iterations = target * 2;

    for (int i = 0; i < iterations; ++i) {
        if (a < x) {
            a++;
        } else if (b < y) {
            b++;
        } else {
            break;
        }
    }

    __VERIFIER_assert(a == x && b == y);
    return 0;
}