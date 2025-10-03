#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
static void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000); // Constraint: n is within a practical range for computation
    int limit = n;
    int i = 0;
    int sum = 0;
    int product = 1;

    while (i < limit) {
        sum += i;
        product *= (i % 5 + 1); // To avoid product being zero
        i++;
    }

    // Assert the conditions that should logically hold true
    __VERIFIER_assert(sum >= 0);

    printf("Sum: %d, Product: %d, Limit: %d\n", sum, product, limit);

    return 0;
}