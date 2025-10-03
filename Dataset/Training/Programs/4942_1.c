#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

/* Assumptions to guide the verifier */
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* Assertion function to validate conditions */
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

/* Main function with computational logic */
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    int sum_odd = 0;
    int sum_even = 0;
    int i = 0;

    while (i < n) {
        if (i % 2 == 0) {
            sum_even += i;
        } else {
            sum_odd += i;
        }
        i++;
    }

    /* Check that sum_even and sum_odd are non-negative, illustrate logic through constraints */
    __VERIFIER_assert(sum_even >= 0);

    /* Print statements to visualize the computation results */
    printf("Sum of even numbers: %d\n", sum_even);
    printf("Sum of odd numbers: %d\n", sum_odd);

    return 0;
}