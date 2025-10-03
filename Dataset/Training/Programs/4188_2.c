#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Assume some initial conditions
    if (!(m >= 0 && n >= 0)) {
        return 0;
    }

    int a = 0;
    int b = 0;
    int sum = 0;

    while (m > 0 || n > 0) {
        if (m > 0) {
            a++;
            sum += a;
            m--;
        }

        if (n > 0) {
            b++;
            sum += b;
            n--;
        }

        // Verify the relation between variables inside the loop
    }

    // Post-condition: Ensure that correct sum is maintained
    __VERIFIER_assert(sum == a * (a + 1) / 2 + b * (b + 1) / 2);

    return 0;
}