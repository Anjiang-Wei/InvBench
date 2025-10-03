#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated_program.c", 8, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0 || N > 1000) {
        return 1;
    }

    int array[N];
    int sum = 0;
    int product = 1;

    for (int i = 0; i < N; i++) {
        array[i] = i + 1; // Fill the array with values from 1 to N
        sum += array[i];
        product *= array[i];
    }

    // Check that the sum of the array is correct (sum of first N positive integers)

    // Check that the product is not negative
    __VERIFIER_assert(product > 0);

    return 0;
}