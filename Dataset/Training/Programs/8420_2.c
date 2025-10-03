#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "new_program.c", 3, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, n;
    long long product, sum;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    if (n <= 0) {
        return 0;
    }

    sum = 0;
    product = 1;
    int counter = 0;
    // Loop to compute the sum and product of the first n natural numbers
    while (counter < n) {
        sum += (counter + 1);
        product *= (counter + 1);
    }

    int result = a * sum + b * product;
    __VERIFIER_assert(result > 0); // The result should be always positive if a and b are positive

    printf("Result: %d\n", result);

    return 0;
}