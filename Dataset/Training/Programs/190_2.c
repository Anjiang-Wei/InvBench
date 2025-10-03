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
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    int sum = 0;

    if (!(m >= 0 && n > 0)) {
        return 0;
    }

    // We aim to compute sum of first n positive integers
    for (int i = 0; i < n; i++) {
        sum += i + 1;
    }

    // Check if the computed sum equals to n*(n+1)/2

    // Add m to sum and check condition
    int newSum = sum + m;
    __VERIFIER_assert(newSum >= sum);

    return 0;
}