#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a, b, result, iterations;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    iterations = __VERIFIER_nondet_int();

    // Assume that a and b are non-negative and iterations is a small positive number
    if (a < 0 || b < 0 || iterations <= 0 || iterations > 10) {
        return 0;
    }

    result = 0;

    while (iterations > 0) {
        // Perform a multiplication-like operation through repeated addition
        result = 0;
        for (int i = 0; i < b; i++) {
            result += a;
        }

        // Check the invariant: result should be a * b

        // Decrease the number of iterations
        iterations--;
    }

    // Final assertion to verify the result of the computation
    __VERIFIER_assert(result == a * b);

    return 0;
}