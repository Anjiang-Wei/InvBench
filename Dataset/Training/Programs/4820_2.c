#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 8, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
        abort();
    }
}

int main() {
    const int MAX_SIZE = 100;
    int count = 0;
    int sum = 0;
    int product = 1;
    int number;

    // Generate a series of non-deterministic numbers
    while (count < MAX_SIZE) {
        number = __VERIFIER_nondet_int();
        assume_abort_if_not(number >= 0 && number <= 10); // Assume numbers are between 0 and 10

        sum += number;
        if (number != 0) {
            product *= number;
        }
        count++;
    }

    // Assertion to check if the sum is reasonably bounded
    // Assertion to ensure product's overflow is handled (product of non-negative numbers can't violate this)
    __VERIFIER_assert(product > 0);

    printf("Sum: %d\nProduct: %d\n", sum, product);

    return 0;
}