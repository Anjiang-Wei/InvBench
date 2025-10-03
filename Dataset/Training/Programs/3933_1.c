#include <assert.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

#define MAX_SIZE 1000000

int main() {
    int a = 0;
    int b = 0;
    int n = __VERIFIER_nondet_int();

    // Constraint condition: n should be greater than zero and within a manageable range
    if (n <= 0 || n > MAX_SIZE) {
        return 0;
    }

    while (a < n) {
        // Meaningful computational logic: simulate two counters moving in different strides
        a++;
        if (a % 5 == 0) {
            b += 2;
        } else {
            b++;
        }
    }

    // Post-condition: ensure the counters are in a known state
    __VERIFIER_assert(b == n + (n / 5));

    return 0;
}