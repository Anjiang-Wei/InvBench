#include <stdio.h>

// "__VERIFIER" functions simulate nondeterministic values, typically used in verification tools.
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-verifiable-program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    int n, sum, prod, limit;
    n = __VERIFIER_nondet_int(); // nondeterministic choice for n
    assume_abort_if_not(n >= 0);

    limit = 10; // Set a limit for the loop to control its execution
    sum = 0;
    prod = 1;
    int i = 0;

    while (1) {
        if (!(i < limit && i < n)) {
            break;
        }

        // Computation logic: calculate sum and product of numbers up to n
        sum += i;
        prod *= (i + 1); // Avoid multiplying by zero for i = 0
        i++;
    }

    __VERIFIER_assert(sum < prod); // Constraint that the sum is always less than the product

    printf("Sum up to %d: %d\n", n, sum);
    printf("Product up to %d: %d\n", n, prod);

    return 0;
}