#include <stdio.h>
#include <stdlib.h>

extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 20);

    int i = 0;
    int result = 1; // Starting with factorial of 0

    while (i < n) {
        i++;
        result *= i;
    }

    // Constraint: factorial(n) should not be equal to zero for n > 0

    // Some meaningful condition about `result`
    if (n == 5) {
        __VERIFIER_assert(result == 120); // 5! = 120
    }

    printf("Factorial of %d is %d\n", n, result);
    return 0;
}