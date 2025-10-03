#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "generated_program.c", 10, "reach_error");
}

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

extern int __VERIFIER_nondet_int(void);

int main() {
    int max_iterations, sum = 0, product = 1;
    int limit = __VERIFIER_nondet_int();

    max_iterations = __VERIFIER_nondet_int();
    assume_abort_if_not(max_iterations > 0 && max_iterations < 100);
    assume_abort_if_not(limit >= 0 && limit < 50);

    for (int x = 0; x < max_iterations; ++x) {
        sum += x;
        product *= (x + 1);
        if (product > limit) {
            break;
        }
    }

    int expected_sum = (max_iterations * (max_iterations - 1)) / 2;

    __VERIFIER_assert(product > 0);

    printf("Final sum is: %d\n", sum);
    printf("Final product is: %d\n", product);

    return 0;
}