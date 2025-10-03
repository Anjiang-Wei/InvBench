#include <stdbool.h>
#include <stdio.h>

void reach_error(void) { printf("Verification error\n"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Assume some initial conditions
    if (a < 0 || b < 0 || n <= 0) {
        return 0;
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a + b;

        // Check conditions within the loop
        __VERIFIER_assert(sum >= (a + b) * (i + 1));

        if (sum < 0) { // Prevent integer overflow
            reach_error();
            break;
        }
    }

    // Final assertion after loop

    printf("Sum is %d\n", sum);
    return 0;
}