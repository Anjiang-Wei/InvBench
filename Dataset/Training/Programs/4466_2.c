#include <stdbool.h>
#include <stdint.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

int __VERIFIER_nondet_int(void);
_Bool __VERIFIER_nondet_bool(void);
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    int a = 0, b = 1, c = 1, i = 0; // Initialise first two Fibonacci numbers and a counter

    while (i < n) {
        int temp = b;
        b = a + b; // Compute next Fibonacci number
        a = temp;

        c++;
    }

    // Another assertion, unrelated to the loop invariants
    __VERIFIER_assert(a + b >= n);

    return 0;
}