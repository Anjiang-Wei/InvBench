#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci-like Sequence
Computes a sequence similar to Fibonacci numbers but with a slight variation.
The sequence is defined as:
  a_0 = 0
  a_1 = 1
  a_n = a_(n-1) + a_(n-2) + 1 for n >= 2

The goal is to compute such a sequence up to a given n and verify a property.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    if (!(n >= 0)) {
        return 0; // Constraint: n should be non-negative
    }

    long long prev2 = 0; // a_0
    long long prev1 = 1; // a_1
    long long curr = 0;

    if (n == 0) {
        curr = prev2;
    } else if (n == 1) {
        curr = prev1;
    } else {
        for (int i = 2; i <= n; ++i) {
            curr = prev1 + prev2 + 1;
            prev2 = prev1;
            prev1 = curr;
        }
    }

    // Assume sequence(a_n) is defined as above
    // The verification assertion checks that for n >= 2, a_n > a_(n-1)
    if (n >= 2) {
        __VERIFIER_assert(curr > prev1 - 1);
    }

    printf("The sequence element at position %d is: %lld\n", n, curr);
    return 0;
}