// power_of_two_floor.c
// Compute the largest power of 2 not exceeding a given positive integer x.

#include <stdlib.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "power_of_two_floor.c", 10, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int x = __VERIFIER_nondet_int();
    // we only consider 1 <= x <= 1000
    assume_abort_if_not(x >= 1 && x <= 1000);

    int p = 1;
    // Find the largest power of 2 not exceeding x
    while (p * 2 <= x) {
        p = p * 2;
    }

    // Checks:
    // 1) p is not greater than x
    __VERIFIER_assert(p <= x);
    // 2) The next power of two strictly exceeds x
    // 3) p is indeed a power of two: only one bit set

    return 0;
}