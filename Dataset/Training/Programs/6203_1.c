#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR:
        reach_error();
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool();

// A function to simulate some computation
int some_computation(int a, int b) {
    return a * a + b * b;
}

int main() {
    int a, b, c;
    int result;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assumptions to limit the range of inputs
    if (a < 0 || a > 100 || b < 0 || b > 100) {
        return 0;
    }

    c = 0;
    result = some_computation(a, b);

    while (__VERIFIER_nondet_bool()) {
        if (c < 50) {
            result += some_computation(c, a);
            c++;
        } else {
            __VERIFIER_assert(c <= 50);
            result -= some_computation(c, b);
            c = 0;
        }
    }

    // Final check on result

    return 0;
}