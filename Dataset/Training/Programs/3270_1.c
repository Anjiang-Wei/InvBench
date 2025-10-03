#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// A program that computes the factorial of a number n
int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 12) {
        // We limit n due to typical integer overflow considerations
        return 0;
    }

    long long factorial = 1;
    int i = 1;

    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verify if factorial computation for some known input such as 5 is correct
    if (n == 5) {
        __VERIFIER_assert(factorial == 120);
    }

    return 0;
}