#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Comments describing the program
   variables and their roles:
   - a, b, c: Input integers
   - x, y, z: Computation variables
   - n: Number of iterations
   - result: Final result to be asserted
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int x = 0, y = 0, z = 0;
    int n = 10; // Number of iterations, you can change this for different tests
    int result = 0;

    // Initial condition check
    if (!(a >= 0 && b >= 0 && c >= 0)) {
        return 0;
    }

    // Loop for some computation
    for (int i = 0; i < n; ++i) {
        x += a * i;
        y += b * i;
        z += c * i;

        // Intermediate assertion to check invariants
        __VERIFIER_assert(x + y + z == (a + b + c) * i * (i + 1) / 2);

        // Modify the result in some meaningful way
        result += x - y + z;
    }

    // Post-condition

    return 0;
}