#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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

int main() {
    int counter = 0;
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int sum = 0, product = 1;

    if (!(a > 0 && b > 0 && c > 0)) {
        return 0;
    }

    while (counter++ < 5) {
        sum += a + b + c;
        product *= a;

        if (product > sum) {
            sum += b;
        } else {
            product *= c;
        }

        // Adding a hypothetical complex constraint
        assume_abort_if_not(sum + product < 1000);
    }

    // The assertions added are not loop invariants
    __VERIFIER_assert(product != 0);

    // Print the final values of sum and product
    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}