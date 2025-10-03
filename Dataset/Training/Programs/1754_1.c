#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int n, a = 1, b = 1, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    // Begin Fibonacci sequence-like computation
    for (i = 2; i < n; ++i) {
        int next = a + b;
        __VERIFIER_assert(next > a && next > b); // Ensure the sequence is strictly increasing
        a = b;
        b = next;
    }

    // Check final condition after the loop
}