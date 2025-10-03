#include <assert.h>
#include <limits.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/*
  Computes the GCD (Greatest Common Divisor) using the Euclidean algorithm.
  Preconditions: a > 0, b > 0
  Postcondition: gcd(a, b) > 0
*/

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Constraints: Avoiding zero or negative inputs.
    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    int x = a;
    int y = b;

    // Loop: Euclidean algorithm to find GCD
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }

    // At this point, x is the GCD of a and b
    __VERIFIER_assert(x > 0);
    return 0;
}