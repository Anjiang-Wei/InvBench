#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-program.c", 5, "reach_error"); }
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

int main() {
    int X, iterations, threshold;
    long long sum, prod;
    X = __VERIFIER_nondet_int();
    iterations = __VERIFIER_nondet_int();
    threshold = __VERIFIER_nondet_int();

    assume_abort_if_not(X >= 0);
    assume_abort_if_not(iterations > 0 && iterations <= 10);
    assume_abort_if_not(threshold >= 0);

    sum = 0;
    prod = 1;

    for (int i = 1; i <= iterations; i++) {
        if (X % 2 == 0) {
            sum += X * i;
            prod *= 2;
        } else {
            sum += i * i;
            prod += X;
        }

        if (sum > threshold) {
            sum *= 2;
            assume_abort_if_not(prod > 0);
        }
    }

    __VERIFIER_assert(prod >= 0);

    if (sum % 2 == 0) {
        printf("Sum is even: %lld\n", sum);
    } else {
        printf("Sum is odd: %lld\n", sum);
    }

    return 0;
}