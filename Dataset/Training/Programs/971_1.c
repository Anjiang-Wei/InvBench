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

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int d = 0;
    int e = 0;

    // Assume initial conditions
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);
    assume_abort_if_not(a + b + c >= 1);

    // Loop with some computational logic
    // Example logic: Move values from a and b to d and e under certain conditions
    while (a > 0 || b > 0 || c > 0) {
        if (a > 0) {
            a--;
            d++;
        }
        if (b > 0) {
            b--;
            e++;
        }
        if (c > 0 && d < e) {
            c--;
            d++;
        }
    }

    // Post-conditions to check
    __VERIFIER_assert(d + e >= 1);

    return 0;
}