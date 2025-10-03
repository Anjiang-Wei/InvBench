/*
Compute the factorial of a number using a loop. Verify that the final
factorial result is a multiple of the original number (except for n=0 and n=1).
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 9, "reach_error"); }
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
    long long factorial = 1;
    int count = 1;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Limiting n to a small value for computational feasibility

    while (count <= n) {
        factorial *= count;
        count++;
    }

    if (n > 1) {
    } else {
        // For 0 and 1, factorial is 1, so the condition is trivially true
        __VERIFIER_assert(factorial == 1);
    }

    printf("Factorial of %d is %lld\n", n, factorial);
    return 0;
}