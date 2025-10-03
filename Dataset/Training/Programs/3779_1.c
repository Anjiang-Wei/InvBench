#include <stdio.h>
#include <stdlib.h>

// Verification and assertion mechanisms
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "multichain.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// A function that will simulate checks similar to assertions in verification tools
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Main computational program
int main() {
    int a, b, c;
    long long sum, product, chain_sum;

    // Non-deterministic inputs for verification
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a > 0 && a <= 10);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b > 0 && b <= 10);
    c = __VERIFIER_nondet_int();
    assume_abort_if_not(c > 0 && c <= 10);

    sum = a + b + c;
    product = a * b * c;
    chain_sum = 0;

    // Simulate a computational process with loop
    int i = 1;
    while (i <= c) {
        chain_sum += (a * i) + (b * (c - i));
        i++;
    }

    __VERIFIER_assert(chain_sum == (a * (c * (c + 1) / 2)) + (b * (c * (c - 1) / 2)));

    // Print results for manual checking
    printf("Sum: %lld\n", sum);
    printf("Product: %lld\n", product);
    printf("Chain Sum: %lld\n", chain_sum);
    return 0;
}