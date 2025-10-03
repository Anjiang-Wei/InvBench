/*
  Integer reverse digit sum
  Computes the sum of digits of an integer and verifies properties.
*/

#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "reverse-sum-ll.c", 8, "reach_error"); }
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
    int input, digit, reverse = 0, original;
    int sum_of_digits = 0;

    input = __VERIFIER_nondet_int();
    assume_abort_if_not(input >= 0 && input <= 99999); // Limit input range to 5 digit numbers

    original = input;

    // Reverse digits and compute sum
    while (input != 0) {
        digit = input % 10;
        reverse = reverse * 10 + digit;
        sum_of_digits += digit;
        input /= 10;
    }

    __VERIFIER_assert(reverse <= 99999);

    // Additional property check

    printf("Original: %d, Reverse: %d, Sum of digits: %d\n", original, reverse, sum_of_digits);

    return 0;
}