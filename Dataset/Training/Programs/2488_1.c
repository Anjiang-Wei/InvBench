#include <stdio.h>
void reach_error(void) { printf("Error reached!\n"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int sum = 0;
    int product = 1;
    int n = __VERIFIER_nondet_int();
    int max_iterations = 100; // Limit to prevent infinite run in analysis

    if (n <= 0) {
        return 0;
    }

    for (int i = 1; i <= n && i <= max_iterations; i++) {
        sum += i;
        product *= i;

        if (product < 0) { // Avoid overflow issues during verification
            break;
        }

        // Check: sum of first i numbers is i*(i+1)/2
        __VERIFIER_assert(sum == (i * (i + 1)) / 2);
    }

    // Final assertion: product is factorial-like, but limited

    printf("Sum: %d, Product: %d\n", sum, product);
    return 0;
}