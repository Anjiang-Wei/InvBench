#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 6, "reach_error"); }
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
}
extern int __VERIFIER_nondet_int(void);

// Program begins here
int factorial(int n) {
    int result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Only compute factorial for 0 <= n <= 12 to avoid integer overflow

    int fact = factorial(n);

    // Check some property about factorial of n. For instance, check if it matches a known value
    if (n == 5) {
    } else if (n == 6) {
        __VERIFIER_assert(fact == 720);
    } else if (n == 7) {
    } // else we don't know, we assume the factorial is computed correctly

    return 0;
}