#include <assert.h>
#include <stdbool.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
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
    int a, b, m, n;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Precondition: initialize 'result' with 0 and m, n > 0
    assume_abort_if_not(m > 0 && n > 0);
    int result = 0;

    // Compute gcd(a, b) using Euclidean algorithm
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    // Now 'a' (or 'b') contains the gcd

    // Compute the LCM using the relation: lcm(m, n) = (m * n) / gcd(m, n)
    int gcd_mn = a;                // We take this as the known gcd for m, n calculation
    int lcm_mn = (m / gcd_mn) * n; // This avoids potential overflow

    // Calculate powers of the computed LCM
    result = 1;
    int count = 0;
    while (count < 4) { // Compute lcm_mn^4
        result *= lcm_mn;
        count++;
    }

    // Postcondition: verify that result contains lcm_mn^4 correctly
    __VERIFIER_assert(result == lcm_mn * lcm_mn * lcm_mn * lcm_mn);

    return 0;
}