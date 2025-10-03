#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "complex_logic.c", 5, "reach_error"); }

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

// A program demonstrating a summation series and its verification
int main() {
    int n = __VERIFIER_nondet_int();
    int i = 1, sum = 0, product = 1;

    if (n <= 0 || n > 50) {
        return 0;
    }

    // Loop to calculate the sum of first n natural numbers
    while (i <= n) {
        sum += i;
        product *= i;
        i++;
    }

    // Check if the calculated sum matches the formula n*(n+1)/2

    // Check if product is greater than zero
    __VERIFIER_assert(product > 0);

    return 0;
}