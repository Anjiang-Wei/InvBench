/* Verify the Collatz Conjecture for a limited range */

#include <stdio.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "collatz-verify.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100);

    int original_n = n;

    while (n != 1) {
        __VERIFIER_assert(n > 0); // n should always be positive in the process
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }

    // If we reach here, it means the conjecture holds for the current n
    printf("Collatz Conjecture holds for %d\n", original_n);

    return 0;
}