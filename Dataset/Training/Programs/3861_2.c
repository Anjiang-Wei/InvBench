#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_assume(int);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;
    int count = 0;

    // Assuming n is a positive number less than 1000
    __VERIFIER_assume(n > 0 && n < 1000);

    while (count < n) {
        sum += count;
        product *= (count + 1);
        count++;
    }

    // Assert that these conditions hold true at the end of the computation
    __VERIFIER_assert(product > 0);

    return 0;
}