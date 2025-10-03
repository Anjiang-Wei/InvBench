#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int factor = __VERIFIER_nondet_int();

    if (factor <= 0) {
        factor = 1; // Ensure a positive factor
    }

    int result = 0;
    int count = 0;

    // Constraint: a and b must be non-negative
    if (a < 0 || b < 0) {
        return 0;
    }

    while (__VERIFIER_nondet_bool()) {
        // Avoid integer overflow
        if (result > __INT_MAX__ - a) {
            break;
        }

        result += a;
        a *= factor;
        b -= factor;

        if (b < 0) {
            break; // Loop condition based on constraint
        }

        count++;
        if (count > 100) {
            break; // Safety limit to prevent infinite loops
        }
    }

    // Postcondition: result is non-negative
    __VERIFIER_assert(result >= 0);

    printf("Result: %d\n", result);

    return 0;
}