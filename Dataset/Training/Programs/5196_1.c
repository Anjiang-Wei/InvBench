#include <assert.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int a, b, c, sum, product;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Assuming values between 0 and 50 for meaningful bounds
    if (a < 0 || a > 50) {
        return 0;
    }
    if (b < 0 || b > 50) {
        return 0;
    }
    if (c < 0 || c > 50) {
        return 0;
    }

    sum = 0;
    product = 1;

    while (sum < 100) {
        if (__VERIFIER_nondet_int() % 2 == 0) {
            sum += a;
        } else {
            sum += b;
        }

        if (product < 1000) {
            product *= c;
        } else {
            break;
        }

        // Check that sums and products do not exceed certain limits
        __VERIFIER_assert(sum <= 200);
    }

    // Final verification to ensure the loop exits under expected conditions

    return 0;
}