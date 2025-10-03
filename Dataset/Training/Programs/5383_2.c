#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }

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
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int prod = 1;
    int counter = 0;

    // To avoid infinite loops, prevent negative or extremely large values
    assume_abort_if_not(n > 0 && n < 50);

    while (counter++ < n) {
        sum = sum + 3;
        prod = prod * 2;

        // Ensure the relationship between sum and prod at each step
    }

    // Final check on the computed sum and product
    __VERIFIER_assert(sum == 3 * n);

    printf("Computed sum: %d, product: %d\n", sum, prod);

    return 0;
}