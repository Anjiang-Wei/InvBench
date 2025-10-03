#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int counter = 0;
    assume_abort_if_not(n >= 0);

    long long sum = 0;
    long long product = 1;

    // Compute the sum of all odd numbers and product of all even numbers up to n
    while (counter < n) {
        counter++;
        if (counter % 2 == 0) {
            product *= counter;
        } else {
            sum += counter;
        }
    }

    __VERIFIER_assert(sum + product >= n);

    // For demonstration purposes (not part of verification logic)
    printf("Sum of odd numbers: %lld\n", sum);
    printf("Product of even numbers: %lld\n", product);

    return 0;
}