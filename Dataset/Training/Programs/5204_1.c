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
    int a = 0;
    int b = 0;
    int m = __VERIFIER_nondet_int(); // some non-deterministic value
    int n = __VERIFIER_nondet_int(); // some non-deterministic value

    if (m <= 0 || n <= 0) {
        return 0; // ensuring m and n are positive
    }

    // initialize complex expression variables
    int sum = 0;
    int diff = 0;

    while (a < m && b < n) {
        sum += a + b;
        diff += a - b;

        if (sum > 1000) {
            break; // prevent overflow in subsequent operations
        }

        a++;
        b += 2;
    }

    // verify that certain properties hold
    __VERIFIER_assert(sum >= 0);

    int product = a * b;
    int quotient = 0;

    if (b != 0) {
        quotient = a / b;
    }

    return 0;
}