#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }

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
    int n, i;
    long long factorial, sum;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Limiting input for factorial calculation

    factorial = 1;
    sum = 0;

    // Calculating factorial of n and accumulating sum of natural numbers
    for (i = 1; i <= n; i++) {
        factorial *= i; // factorial = factorial * i
        sum += i;       // sum = sum + i

        // Checking if factorial and sum satisfy specific conditions
        __VERIFIER_assert(sum == (i * (i + 1)) / 2);
    }

    // Final checks after loop

    printf("Factorial of %d is %lld\n", n, factorial);
    printf("Sum of first %d natural numbers is %lld\n", n, sum);

    return 0;
}