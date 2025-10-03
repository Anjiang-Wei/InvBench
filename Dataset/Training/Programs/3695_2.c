#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "__FILE__", __LINE__, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

extern int __VERIFIER_nondet_int();
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int computeSumOfSquares(int limit) {
    int sum = 0;
    for (int i = 1; i <= limit; i++) {
        sum += i * i;
    }
    return sum;
}

int main() {
    int limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit >= 0); // We assume the limit is non-negative

    int sumOfSquares = computeSumOfSquares(limit);

    // A constraint: If limit is 0, sumOfSquares must be 0.
    if (limit == 0) {
    }

    // Simulating a condition check, similar to other examples.
    int anotherSum = 0;
    int counter = 0;
    while (counter <= limit) {
        anotherSum += counter;
        counter++;
    }

    // Perform another assertion related to loop
    if (limit < 10) {
        __VERIFIER_assert(anotherSum == (limit * (limit + 1)) / 2);
    }

    printf("Sum of squares up to %d is: %d\n", limit, sumOfSquares);
    return 0;
}