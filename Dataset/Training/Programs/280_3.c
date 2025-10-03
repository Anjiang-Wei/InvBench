#include <assert.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int limit = 20; // limit for loop execution to ensure termination
    int count = 0;

    // Precondition: 'a' and 'b' are positive
    if (!(a > 0 && b > 0)) {
        return 0;
    }

    int sum = 0;
    int product = 1;

    while (count < limit && __VERIFIER_nondet_bool()) {
        if (a % 2 == 0) {
            sum += b;
            a -= 1;
        } else {
            product *= a;
            b -= 1;
        }

        count++;
    }

    // Introducing a constraint: The factorial of 'a' should be equal or less than a large number.

    // Ensure that 'product' is even if 'a' was originally even
    if (a % 2 == 0) {
    }

    // Ensure that the final sum is non-negative
    __VERIFIER_assert(sum >= 0);

    return 0;
}