/* Program to sum digits of a number until a single digit is obtained */

#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "digitsum.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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
    int num = __VERIFIER_nondet_int();
    assume_abort_if_not(num >= 0); // Only non-negative integers

    int original_num = num;
    int digit_sum = 0;
    int loop_counter = 0;

    // Calculate the sum of digits until a single digit is left
    while (num >= 10) {
        digit_sum = 0;
        int current_num = num;
        while (current_num > 0) {
            digit_sum += current_num % 10;
            current_num /= 10;
        }
        num = digit_sum;
        loop_counter++;
    }

    __VERIFIER_assert(num >= 0 && num <= 9); // Final single digit result must be in the range 0-9

    printf("The digital root of %d is %d, computed in %d loop iterations.\n", original_num, num, loop_counter);

    return 0;
}