#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
  This program initializes three variables: m, x, and t.
  It ensures m is positive and initializes x and t to zero.
  The loop condition depends on non-deterministic values and an additional variable, p.
  It incrementally increases x while decreasing t, asserting a condition at the end.
*/
int main() {
    int m = __VERIFIER_nondet_int();
    int x = 0;
    int t = 10;                      // A fixed value for demonstration
    int p = __VERIFIER_nondet_int(); // Additional constraint variable

    if (!(m > 0 && p > m)) {
        return 0;
    }

    while (x < m && p > m) {
        x++;
        t--; // Decrease t with each iteration
    }

    // Check some condition based on the loop's result
    __VERIFIER_assert(x == m && t == 10 - m);
    return 0;
}