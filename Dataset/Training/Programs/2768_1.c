#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main(void) {
    int n = __VERIFIER_nondet_int();
    int factorial = 1;
    int i = 1;

    // Ensure n is non-negative
    assume_abort_if_not(n >= 0);

    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Ensure that factorial of 0 is correctly computed
    if (n == 0) {
        __VERIFIER_assert(factorial == 1);
    }

    // Output result (not part of verification, for illustrative purposes)
    printf("Factorial of %d is %d\n", n, factorial);

    return 0;
}