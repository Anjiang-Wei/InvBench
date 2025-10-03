#include <stdio.h>

// Example of using symbolic execution and verification tools in C programs

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR:
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, n;
    long long product, sum, i;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 1 && a <= 10);
    assume_abort_if_not(b >= 1 && b <= 10);
    assume_abort_if_not(n >= 1 && n <= 10);

    product = 1;
    sum = 0;
    i = 0;

    // A loop to calculate product and sum over n iterations
    while (i < n) {
        sum += a + b;
        product *= a * b;

        // Avoid overflows for product
        assume_abort_if_not(product >= 1 && product <= 1000000);

        if (sum > 100) { // Some arbitrary constraint to potentially stop the loop
            break;
        }

        i++;
    }

    // Ensuring that the final product and sum are within expected bounds
    __VERIFIER_assert(product >= 1 && product <= 1000000);

    // Output the calculated values
    printf("Product: %lld, Sum: %lld\n", product, sum);

    return 0;
}