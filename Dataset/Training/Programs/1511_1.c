#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int calculate_factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int m = __VERIFIER_nondet_int();

    if (!(m >= 0 && m <= 10)) {
        return 0;
    }

    int result = calculate_factorial(m);

    // Verify the basic property of factorial
    // (m+1)! = (m+1) * m!
    int next_result = result * (m + 1);
    __VERIFIER_assert(next_result / (m + 1) == result);

    return 0;
}