#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 10, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0); // Ensures n is positive
    int i, a = 0, b = 1, next = 0;

    // Simple Fibonacci sequence calculation
    for (i = 1; i <= n; ++i) {
        next = a + b; // Computing next number in the sequence
        a = b;
        b = next;

        // Assert ensures the relationship in the Fibonacci sequence
        // We use this to demonstrate verifier check capabilities, not implying this as a loop invariant
    }

    // Check that the nth Fibonacci number is valid
    __VERIFIER_assert(next > 0);

    printf("Fibonacci number at position %d is %d\n", n, next);
    return 0;
}