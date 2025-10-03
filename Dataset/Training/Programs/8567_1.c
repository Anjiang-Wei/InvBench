#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "new_program.c", 6, "reach_error");
}

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
    assume_abort_if_not(num >= 1 && num <= 50);

    int sum = 0;
    int product = 1;

    // Squaring numbers and accumulating sums and products
    for (int i = 1; i <= num; ++i) {
        sum += i * i;
        product *= i;
        __VERIFIER_assert(sum >= i); // Assert that the sum is always at least the current number
        if (product > 10000) {
            break; // Prevent overflow in this simplistic analysis
        }
    }

    __VERIFIER_assert(sum >= num); // Final assertion ensuring the condition holds
    printf("Final sum of squares: %d\n", sum);
    printf("Final product: %d\n", product);

    return 0;
}