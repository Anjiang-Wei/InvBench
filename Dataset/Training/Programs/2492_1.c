#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // Ensure constraints on initial values
    if (a < 0 || b < 0) {
        return 0;
    }

    while (__VERIFIER_nondet_bool()) {
        if (a % 2 == 0) {
            // If 'a' is even, increment 'b'
            b++;
        } else {
            // If 'a' is odd, decrease 'b'
            b--;
        }

        // Update sum and product
        sum += a + b;
        product *= a * b;

        // Change the value of 'a' to gradually approach a termination condition
        a = (a - 1 > 0) ? a - 1 : 0;
    }

    // Final property check
    __VERIFIER_assert(sum >= 0);
    return 0;
}