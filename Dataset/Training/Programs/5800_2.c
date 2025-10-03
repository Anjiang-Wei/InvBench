#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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
    long long factorial, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Ensuring n is within range to avoid overflow

    factorial = 1;
    i = 1;

    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Assert that factorial is greater than 0 for positive n
    if (n > 0) {
    } else {
        // Factorial of 0 is 1
        __VERIFIER_assert(factorial == 1);
    }

    printf("Factorial of %d is %lld\n", n, factorial);

    return 0;
}