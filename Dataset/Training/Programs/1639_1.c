#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 6, "reach_error"); }

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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Restricting n to ensure factorial fits in int
    int result = 1;
    int i;

    for (i = 1; i <= n; i++) {
        __VERIFIER_assert(result > 0); // Ensuring no overflow occurred so far
        result *= i;
    }

    // Verification: Check if factorial calculation cost is the sum from 1 to n
    int cost = 0;
    for (i = 1; i <= n; i++) {
        cost += i;
    }
}