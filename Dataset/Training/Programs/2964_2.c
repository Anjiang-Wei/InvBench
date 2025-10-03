#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a, b, n;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Precondition: a >= 0, b >= 0, n > 0
    if (!(a >= 0 && b >= 0 && n > 0)) {
        return 0;
    }

    int sum = a + b;
    int diff = a - b;
    int counter = 0;
    int product = 0;

    // Loop: compute product = a * b using addition
    while (counter < b) {
        product += a;
        counter++;
    }

    // Verify the product using basic identity

    // Simple computation to ensure sum and diff are consistent
    int result = sum - diff;

    // Post condition: result should be double of b
    __VERIFIER_assert(result == 2 * b);

    return 0;
}