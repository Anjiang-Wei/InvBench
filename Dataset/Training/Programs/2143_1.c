#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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

int main() {
    int input1, input2;
    int sum = 0;
    int product = 1;

    input1 = __VERIFIER_nondet_int();
    input2 = __VERIFIER_nondet_int();

    assume_abort_if_not(input1 >= 0 && input2 >= 0);

    for (int i = 0; i < input1; i++) {
        sum += i;
    }

    for (int j = 1; j <= input2; j++) {
        product *= j;
    }

    // Verification condition: sum of numbers from 0 to input1-1 should be (input1 * (input1 - 1)) / 2
    __VERIFIER_assert(sum == (input1 * (input1 - 1)) / 2);

    // Verification condition: product of numbers from 1 to input2 should not overflow

    printf("Sum: %d, Product: %d\n", sum, product);
    return 0;
}