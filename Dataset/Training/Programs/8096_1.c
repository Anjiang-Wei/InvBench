#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { assert(0); }

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

// Function to perform some calculations
int compute_value(int a, int b, int c) {
    return a * a + b * b + c * c;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int result = 0;
    int counter = 0;

    // Precondition constraints
    assume_abort_if_not(a >= 0 && b >= 0 && c >= 0);

    // Main loop with assertions
    while (counter < 100) {
        // Perform computation and accumulate the result
        int interim_result = compute_value(a, b, c);
        result += interim_result;

        // Increment variables
        a++;
        b++;
        c++;
        counter++;

        // Assert properties
        __VERIFIER_assert(result >= 0);
    }

    // Postcondition check

    return 0;
}