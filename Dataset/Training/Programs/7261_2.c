#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

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

int counter = 0;

int main() {
    // Initialization of the variables
    int a, b, sum, product;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assuming non-deterministic integers are non-negative
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    sum = 0;
    product = 1; // Start product as 1 to avoid multiplying by zero

    // Loop with a constraint on the counter to prevent infinite loops
    while (counter++ < 15) {
        // Adding 'a' to sum, and multiplying 'b' to product
        sum = sum + a;
        product = product * (b + 1); // Adding 1 to prevent multiplication by zero

        // Break if certain condition is met
        if (sum > 1000 || product > 1000) {
            break;
        }
    }

    // A final condition to ensure properties of the program
    __VERIFIER_assert(product > 0);

    printf("Final sum: %d\n", sum);
    printf("Final product: %d\n", product);

    return 0;
}