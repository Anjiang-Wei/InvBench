#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int num, temp, sum = 0;
    num = __VERIFIER_nondet_int();

    // Ensure num is positive and less than a threshold
    assume_abort_if_not(num > 0 && num < 1000);

    // Calculate the sum of digits of num
    temp = num;
    while (temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }

    // The sum of the digits of a number should be less than 100 for the given constraint
    __VERIFIER_assert(sum < 100);

    printf("Sum of digits of %d is %d\n", num, sum);

    return 0;
}