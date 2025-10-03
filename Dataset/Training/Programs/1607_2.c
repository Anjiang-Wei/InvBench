#include <stdio.h>
#include <stdlib.h>

extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
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
    // Nondeterministic inputs
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0 && b > 0 && a < 100 && b < 100); // some logical preconditions

    int sum = 0;
    int product = 1;

    while (a > 0) {
        sum += b;
        product *= b;

        // Decrease `a` to eventually terminate the loop
        a--;

        // To maintain large values in check (preventing overflows)
        if (sum > 100000 || product > 100000) {
            break;
        }
    }

    // Final assertions
    __VERIFIER_assert(product >= 1);

    // Print the results
    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}