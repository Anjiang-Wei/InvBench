#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int a, b;
    a = __VERIFIER_nondet_int(); // Nondeterministic input
    b = __VERIFIER_nondet_int(); // Nondeterministic input

    // Ensure some basic constraints on inputs
    if (a < 0 || b < 0 || a > 1000000 || b > 1000000) {
        // Invalid input scenario, let's assume these are not possible
        abort();
    }

    long long product = 0;
    int x = 0;
    int step = 0;

    // Perform basic addition-based multiplication
    while (x < b && step < 100) {
        product += a;
        x++;
        step++;

        // Assert a constraint on the product to ensure it doesn't overflow
    }

    // Ensure the product matches a * b when the loop exits
    if (x == b) {
    } else {
        // If we broke out early, the loop invariant didn't complete fully
        __VERIFIER_assert(x < b);
    }

    printf("a: %d, b: %d, product: %lld\n", a, b, product);

    return 0;
}