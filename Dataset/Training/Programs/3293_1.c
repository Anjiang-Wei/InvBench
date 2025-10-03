#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Assume meaningful constraints on the inputs
    assume_abort_if_not(a >= 0 && b >= 0 && c >= 0);

    // Compute the greatest common divisor (GCD) using the Euclidean algorithm
    int x = a;
    int y = b;
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    int gcd_ab = x;

    // Further compute another value with c to simulate additional complexity
    x = gcd_ab;
    y = c;

    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    int gcd_abc = x;

    // Assert relationship condition between inputs
    if (a > 0 && b > 0 && c > 0) {
        __VERIFIER_assert(gcd_abc >= 1);
    }

    return 0;
}