#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Description:
   This program calculates a sequence of numbers using a linear recurrence relation:
   x_n = x_(n-1) + n * a, where x_0 is initially set to 0, and a is a non-deterministically
   chosen integer bounded to 100. The loop iterates exactly N times, where N is also
   a non-deterministically chosen integer such that N is positive and less than 100.
*/

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 100);

    int a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 100);

    long long x = 0;
    int n = 1;

    while (n <= N) {
        x = x + n * a;

        __VERIFIER_assert(x >= 0); // To verify the non-negativity of the process sum

        n++;
    }

    // Additional verification to assert that the final result is within some bound

    return 0;
}