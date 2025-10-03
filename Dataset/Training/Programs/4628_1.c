#include <assert.h>

extern int __VERIFIER_nondet_int(void);
void reach_error(void) { assert(0); }
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
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0 && b > 0);

    // Initialize loop variables
    int sum = 0;
    int product = 1;
    int count = 0;

    // Loop that performs operations depending on the parity of 'c'
    while (count < a + b) {
        if (c % 2 == 0) {
            sum += count;
        } else {
            product *= (count + 1); // Avoid multiplication by zero
        }
        count++;
    }

    // Assertions ensuring properties about the result
    __VERIFIER_assert(sum >= 0);

    return 0;
}