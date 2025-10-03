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

int main(void) {
    int a, b;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume limits for a and b to ensure they are positive and reasonably sized
    assume_abort_if_not(a >= 1 && a <= 10);
    assume_abort_if_not(b >= 1 && b <= 10);

    int result = 0;
    int counter = 0;

    // Loop to calculate a*b as a sum of a, b times (i.e. repeated addition)
    while (counter < b) {
        result += a;
        counter++;
    }

    // Conditional logic to manipulate result further
    if (result % 2 == 0) {
        result /= 2;
    } else {
        result = result * 3 + 1;
    }

    // Check that calculated result is always positive
    __VERIFIER_assert(result > 0);

    return 0;
}