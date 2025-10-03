#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "complex_count.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int();
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
    int a, b, c, n;
    int sum = 0;

    // Nondeterministically choose values for a, b, c
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 100);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 100);
    c = __VERIFIER_nondet_int();
    assume_abort_if_not(c >= 0 && c <= 100);

    // Set a nondeterministic limit for the loop count
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 1000);

    while (n > 0) {
        if (a < b) {
            a += c;
        } else {
            b += c;
        }
        sum += a + b + c;
        n--;
    }

    // Verify sum is non-negative.
    __VERIFIER_assert(sum >= 0);

    return 0;
}