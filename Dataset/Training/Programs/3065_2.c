#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    int n, i;
    long long factorial = 1;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // reasonably small value to prevent overflow

    i = 1;

    // Calculate the factorial iteratively
    while (i <= n) {
        if (factorial < 0) { // Check overflow
            reach_error();
        }
        i++;
    }

    // Check the final result is correct
    if (n == 0 || n == 1) {
        __VERIFIER_assert(factorial == 1);
    } else {
    }

    printf("Factorial of %d is %lld\n", n, factorial);

    return 0;
}