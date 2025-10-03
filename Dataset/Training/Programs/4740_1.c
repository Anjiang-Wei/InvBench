#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }

extern unsigned int __VERIFIER_nondet_uint(void);
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

int main(void) {
    unsigned int count = 0;
    unsigned int limit = __VERIFIER_nondet_uint();
    unsigned int sum = 0;
    unsigned int product = 1;

    while (count < limit) {
        sum += count;
        product *= (count % 2 == 0) ? 2 : 1; // Double the product for even numbers

        if (product >= 1000) {
            break;
        }
        count++;
    }

    // The logic here specifies if we've correctly calculated the sum and maintained a product condition
    // pertaining to even numbers besides a break due to product >= 1000
    __VERIFIER_assert((product < 1000 && count >= limit) ||
                      (product >= 1000 && (product % 2 == 0)));

    printf("Limit: %u, Count: %u, Sum: %u, Product: %u\n", limit, count, sum, product);
    return 0;
}