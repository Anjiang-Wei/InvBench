#include <assert.h>
#include <stdbool.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern unsigned __VERIFIER_nondet_unsigned(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int gcd(int a, int b) {
    // Compute the greatest common divisor using the Euclidean algorithm
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    if (a <= 0 || b <= 0) {
        return 0;
    }

    int original_a = a;
    int original_b = b;

    int counter = 0;

    while (counter++ < 2) { // Limit counter for demonstration
        if (!(b != 0)) {
            break;
        }
        int temp = a % b;
        a = b;
        b = temp;
    }

    // Perform some validations
    int result = gcd(original_a, original_b);
    __VERIFIER_assert(a > 0);

    return 0;
}