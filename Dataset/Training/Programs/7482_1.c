#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Abstract:
   Fibonacci Sequence Verification
   Calculate Fibonacci numbers iteratively and assert properties.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    int a = 0, b = 1, temp;

    if (!(n >= 0)) {
        return 0;
    }

    for (int i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }

    __VERIFIER_assert(b >= 0); // Fibonacci numbers should always be non-negative

    return 0;
}