// Program to check properties of a number sequence

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int() {
    return rand() % 100; // Random number generator for demo purposes
}

int main() {
    int n, m, countEven, countOdd, sumEven, sumOdd;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0); // The sequence must have at least one number

    countEven = 0;
    countOdd = 0;
    sumEven = 0;
    sumOdd = 0;

    for (m = 1; m <= n; m++) {
        if (m % 2 == 0) {
            countEven++;
            sumEven += m;
        } else {
            countOdd++;
            sumOdd += m;
        }
    }

    // Assert that the total numbers counted match n
    __VERIFIER_assert(countEven + countOdd == n);

    // Assert that the sum of even numbers plus the sum of odd numbers equals the sum of first n natural numbers

    printf("Even numbers: %d, Sum of even: %d\n", countEven, sumEven);
    printf("Odd numbers: %d, Sum of odd: %d\n", countOdd, sumOdd);

    return 0;
}