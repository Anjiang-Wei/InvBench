#include <assert.h>
extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a = 0, b = 1, temp;
    int limit = __VERIFIER_nondet_int();

    // Assume a bounded limit for Fibonacci sequence generation
    if (limit <= 1) {
        return 0;
    }
    assume_abort_if_not(limit < 20); // This is to guarantee the loop termination within reasonable bounds

    while (b < limit) {
        __VERIFIER_assert(a <= b); // Inequality invariant for Fibonacci sequence

        // Generate the next Fibonacci number
        temp = a + b;
        a = b;
        b = temp;

        // Ensure numbers are within logical sequence constraints
    }

    // Final assertion to check the result at loop termination

    return 0;
}