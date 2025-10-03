#include <assert.h>
#include <stdlib.h>

// Custom error function for verification
void reach_error(void) { assert(0); }

// Assumption helper function
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Assertion helper function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

// External nondeterministic integer function
extern int __VERIFIER_nondet_int(void);

int main() {
    // Nondeterministically select initial values for a, b, and limit
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int limit = __VERIFIER_nondet_int();

    // Ensure the initial constraints
    if (!(a >= 0 && b >= 0 && limit > 0)) {
        return 0;
    }

    // Exec time variables
    int exec_time = 0;
    int count = 0;

    // Loop simulating computational tasks
    while (exec_time < limit) {
        // Perform some operations
        a += b;
        b += a % 3;

        // Track number of executions
        count++;
        exec_time += 1;

        // The assertion ensures a constraint relative to 'limit'
    }

    // Post-condition check
    __VERIFIER_assert(count == limit); // This should cause an error because count may not always be equal to limit

    return 0;
}