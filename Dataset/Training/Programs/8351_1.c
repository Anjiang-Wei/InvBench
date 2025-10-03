#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int a, b, p, q;
    a = 1; // Start value for sequence
    b = 1; // Start value for sequence
    p = 1; // Parameter for controlling the sequence
    q = __VERIFIER_nondet_int();

    if (q < 1) {
        q = 1; // Ensure q is at least 1
    }

    // Fibonacci-like sequence
    while (p <= 10) {
        __VERIFIER_assert(a >= 1 && b >= a); // Ensure a non-decreasing sequence

        int temp = b;
        b = a + b;
        a = temp;

        p++;
    }

    // Verify that the sequence has grown significantly

    return 0;
}