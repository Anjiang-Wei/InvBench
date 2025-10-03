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
    int sum = 0;
    int difference = 0;

    // Initial conditions
    if (!(a >= 0 && b >= 0)) {
        return 0;
    }

    // Loop to accumulate 'b' into 'sum' and calculate a simple difference condition
    while (b > 0) {
        sum += a;
        b--;
    }

    // Intentionally constructing a similar structure with swapping
    if (sum > a) {
        difference = sum - a;
    } else {
        difference = a - sum;
    }

    // Postcondition to verify the logic
    __VERIFIER_assert(difference >= 0 && sum >= 0);

    return 0;
}