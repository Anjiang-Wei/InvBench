#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", __LINE__, "reach_error"); }
int __VERIFIER_nondet_int(void);
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
    assume_abort_if_not(n >= 0 && n <= 12); // Limit to prevent overflow in factorial calculation
    int factorial = 1;
    int i = 1;
    int counter = 0;

    while (counter++ < 15) {
        if (i > n) {
            break;
        }
        factorial *= i; // Calculate the factorial
        i++;
    }

    // Some condition to be maintained
    __VERIFIER_assert(factorial > 0 && factorial <= 479001600); // 12! = 479001600, upper limit due to the assumption

    printf("Factorial of %d is %d\n", n, factorial);
    return 0;
}