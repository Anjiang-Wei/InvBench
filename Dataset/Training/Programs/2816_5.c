#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 4, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Assume some initial conditions
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);
    assume_abort_if_not(c >= 0 && c <= 100);

    int sum = 0;
    int product = 1;
    int max_val = a;

    // Find maximum of the three numbers
    if (b > max_val) {
        max_val = b;
    }
    if (c > max_val) {
        max_val = c;
    }

    // Compute sum and product
    for (int i = 0; i < 10; i++) {
        sum += (a + b + c);
        product *= (a * b * c + 1); // Adding 1 to avoid multiplication by zero
    }

    // Adding some assertions to verify properties
    __VERIFIER_assert(max_val >= c);

    // Output the results
    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);
    printf("Max: %d\n", max_val);

    return 0;
}