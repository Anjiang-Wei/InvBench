#include <assert.h>

// Function to mimic the external features in examples
void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Assume function to provide constraints to the solver
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, c;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Preconditions for the execution
    assume_abort_if_not(a >= 0 && b >= 0 && c >= 0);
    assume_abort_if_not(b <= 100); // restrict range to avoid overflow in loop

    int sum = 0;
    int product = 1;
    int i = 0;

    while (i < b) {
        sum += a;     // Increasing sum by a in each iteration
        product *= c; // Multiplying product by c in each iteration
        i++;
    }

    // Postcondition to check after the loop
    __VERIFIER_assert(sum == a * b);

    return 0;
}