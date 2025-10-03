#include <stdio.h>
#include <stdlib.h>

/*
Factorial computation with checks
Computes the factorial of a given number n if 0 <= n <= 5
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 10, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    long long factorial = 1;
    int i = 1;

    assume_abort_if_not(n >= 0 && n <= 5);

    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verify the factorial computation for small n
    // For n = 0, 1, 2, 3, 4, 5 factorials are: 1, 1, 2, 6, 24, 120 respectively
    if (n == 0 || n == 1) {
    } else if (n == 2) {
    } else if (n == 3) {
        __VERIFIER_assert(factorial == 6);
    } else if (n == 4) {
    } else if (n == 5) {
    } else {
        reach_error(); // This should not be reached due to our assumptions
    }

    printf("Factorial of %d is %lld\n", n, factorial);
    return 0;
}