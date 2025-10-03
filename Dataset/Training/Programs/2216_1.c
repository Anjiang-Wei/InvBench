#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }
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

// Externally defined function to provide non-deterministic integer values
extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    // Only consider positive values of n
    assume_abort_if_not(n > 0 && n <= 1000);

    int counter = 0;
    int sum_even = 0;
    int sum_odd = 0;

    while (counter < n) {
        if (counter % 2 == 0) {
            sum_even += counter;
        } else {
            sum_odd += counter;
        }
        counter++;
    }

    // Assert that the sum of even and odd maintains certain conditions
    __VERIFIER_assert(sum_even >= 0);

    printf("Sum of even indices: %d\n", sum_even);
    printf("Sum of odd indices: %d\n", sum_odd);

    return 0;
}