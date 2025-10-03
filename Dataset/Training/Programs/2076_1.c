#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int(); // Integer to be manipulated
    int b = __VERIFIER_nondet_int(); // Integer to be manipulated
    int c = __VERIFIER_nondet_int(); // Integer to be manipulated

    // Assumption: a, b, c are non-negative and at least one is non-zero
    if (!(a >= 0 && b >= 0 && c >= 0 && (a > 0 || b > 0 || c > 0))) {
        return 0;
    }

    // Calculation variables
    int sum = 0;
    int product = 1;

    while (a > 0 || b > 0 || c > 0) {
        // If 'a' is greater than zero, add it to sum and decrease
        if (a > 0) {
            sum += a;
            a--;
        }

        // If 'b' is greater than zero, subtract it from sum and decrease
        if (b > 0) {
            sum -= b;
            b--;
        }

        // If 'c' is greater than zero, multiply it with product and decrease
        if (c > 0) {
            product *= c;
            c--;
        }
    }

    // Check if the sum and product satisfy some condition
    if (sum >= 0) {
        __VERIFIER_assert(sum + product > 0);
    } else {
    }

    return 0;
}