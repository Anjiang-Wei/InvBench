#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_verifier.c", 5, "reach_error"); }

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
    int x = 0, threshold = __VERIFIER_nondet_int(), count = 0;

    assume_abort_if_not(threshold >= 0 && threshold <= 100);

    while (__VERIFIER_nondet_int()) {
        if (x % 2 == 0) {
            x += 3;
        } else {
            x *= 2;
        }
        count++;

        if (count > threshold) {
            break; // Avoid infinite looping
        }
    }

    __VERIFIER_assert(x >= 0);

    return 0;
}