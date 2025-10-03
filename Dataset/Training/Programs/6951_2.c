#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "my_program.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int();

int main() {
    int n = __VERIFIER_nondet_int();
    int i = 0, sum = 0, product = 1;

    while (i < n) {
        i++;
        sum += i;
        product *= i;
    }

    // Constraint ensuring the result remains within expected bounds
    if (n > 0) {
    } else {
        __VERIFIER_assert(sum == 0);
    }

    printf("Sum: %d, Product: %d\n", sum, product);
    return 0;
}