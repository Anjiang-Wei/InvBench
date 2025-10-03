#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void exit(int);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int limit;
    limit = __VERIFIER_nondet_int();
    if (limit < 0 || limit > 10) {
        return 0; // Only consider limits between 0 and 10 for simplicity
    }

    int sum = 0;
    int i = 1;

    // Loop to calculate the sum of even numbers up to a certain limit
    while (i <= limit) {
        if (i % 2 == 0) {
            sum += i;
        }
        i++;
    }

    // Assert that the sum is non-negative and within a reasonable range
    __VERIFIER_assert(sum >= 0 && sum <= 30);

    // Output the result
    printf("Sum of even numbers up to %d is %d\n", limit, sum);

    return 0;
}