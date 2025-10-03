/*
  Fibonacci Sequence Sum
  Computes the sum of even-valued terms in the Fibonacci sequence that do not exceed a given limit.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-sum.c", 7, "reach_error"); }
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
    int limit;
    long long sum, a, b, temp;

    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0);

    // Initialize Fibonacci numbers
    a = 1;
    b = 2; // The first even Fibonacci number
    sum = 2;

    while (b <= limit) {
        temp = a + b;
        a = b;
        b = temp;

        if (b % 2 == 0 && b <= limit) {
            sum += b;
        }
    }

    printf("Sum of even Fibonacci terms up to %d: %lld\n", limit, sum);

    // Verification: Sum of even numbers should not be less than 2 if limit >= 2
    __VERIFIER_assert(limit < 2 || sum >= 2);

    return 0;
}