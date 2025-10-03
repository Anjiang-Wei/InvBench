#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Assuming inputs are non-negative for the sake of this computation
    if (!(a >= 0 && b >= 0 && c >= 0)) {
        return 0;
    }

    // Ensure a is less than or equal to b initially
    if (!(a <= b)) {
        return 0;
    }

    while (a < b) {
        if (a % 2 == 0) {
            a += 2 * c; // Increase by even multiple of c if a is even
            c++;
        } else {
            a += c; // Increase by c if a is odd
            c += 2;
        }

        // Decreasing b to eventually meet or cross a
        if (b % 3 == 0) {
            b -= 3; // Decrease by 3 if divisible by 3
        } else {
            b--; // Otherwise, decrease by 1
        }
    }

    // Ensure that after the loop the condition holds
    __VERIFIER_assert(a >= b && a - b <= 2 * c);

    return 0;
}