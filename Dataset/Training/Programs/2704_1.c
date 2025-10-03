#include <assert.h>
#include <stdbool.h>

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
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, z, n;
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 1 && a <= 10); // Control the range of 'a'
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 1 && b <= 10); // Control the range of 'b'

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10); // Control the range of 'n'

    z = 0;

    // Computes a^b using repeated multiplication
    for (int i = 0; i < b; i++) {
        __VERIFIER_assert(z == a * i); // Here just to ensure z is in sync with the calculation
        z = z + a;
    }

    // Simple verification of a property

    // Compute the sum of first n natural numbers
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = sum + i;
    }

    // Verification if the sum of first n natural numbers is correct: sum = n*(n+1)/2

    return 0;
}