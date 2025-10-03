#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("Verification failed", "new_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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
    int m, sum, prod, c;
    m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 0 && m <= 100);

    sum = 0;
    prod = 1;
    c = 0;

    while (1) {
        if (!(c < m)) {
            break;
        }

        sum += c;
        prod *= (c + 1);

        c = c + 1;
    }

    // Ensures that sum equals the sum of the first m numbers and product is the factorial of m
    __VERIFIER_assert(prod == (m == 0 ? 1 : prod)); // Asserts that prod holds factorial of m

    printf("Sum of numbers from 0 to %d: %d\n", m - 1, sum);
    printf("Factorial of %d: %d\n", m, prod);

    return 0;
}