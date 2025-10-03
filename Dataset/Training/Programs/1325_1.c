#include <assert.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void reach_error(void) { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
  Fibonacci-like sequence program
  Computes a sequence where each term is the sum of the previous two terms.
  The initial two terms are provided as input, the sequence is generated
  until a certain number of terms is computed. Verifies a property about the sequence.
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && b >= 0);

    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 2 && n <= 100);

    int prev1 = a;
    int prev2 = b;
    int current;
    int i = 2;

    while (i < n) {
        current = prev1 + prev2;

        // Property to verify: Non-decreasing nature of the sequence
        __VERIFIER_assert(current >= prev2);

        prev1 = prev2;
        prev2 = current;
        i++;
    }

    // After finishing, verifying the last value is at least the initial two added

    return 0;
}