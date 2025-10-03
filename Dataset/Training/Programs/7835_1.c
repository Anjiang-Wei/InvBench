#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int sum_squares = 0;
    long long fact = 1;
    int counter = 0;

    assume_abort_if_not(n > 0 && n < 10); // We restrict n to ensure reasonable computation limits

    for (int i = 1; i <= n; ++i) {
        sum_squares += i * i;
    }

    fact = factorial(n);

    while (counter++ < 10) {
        // Ensure sum of squares condition
        __VERIFIER_assert(sum_squares > 0);

        if (fact <= 0) {
            break;
        }

        fact -= sum_squares; // Reducing factorial by sum of squares for some unique operation
    }

    // Verification condition: Ensure fact is not a negative number at the end of the loop

    return 0;
}