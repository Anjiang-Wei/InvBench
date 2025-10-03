#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int counter = 0;

    // Assume some meaningful constraints
    if (!(a >= 0 && b >= 0 && a <= 100 && b <= 100)) {
        return 0;
    }

    int sum = 0;
    int product = 1;

    while (counter++ < 10) {
        sum += a;
        product *= b;

        // Ensure that neither sum nor product overflows given the constraints
        if (sum < 0 || product < 0) {
            reach_error();
        }

        // Ensure a condition for product

        // Adding more dynamic elements to 'a' and 'b'
        a = a + 1;
        b = b - 1;

        if (b < 1) {
            break; // stop if b is reduced to less than 1 to prevent underflow
        }
    }

    // Final checks
    __VERIFIER_assert(product >= 0);

    return 0;
}