// Program to compute a series of numbers following specific recurrent relations

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
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n, m, a, b, c;
    n = __VERIFIER_nondet_int();            // Auxiliary input control
    assume_abort_if_not(n >= 0 && n <= 10); // Limit n to avoid infinite input possibilities

    // Initial values for recursive computation
    a = 1;
    b = 2;
    c = 3;
    int counter = 0;
    m = 10;

    while (counter < m) {
        // Recurrence relations
        int temp = a;
        a = b;
        b = c;
        c = temp + b + c;

        // Verification conditions (without asserts used as invariants)
        __VERIFIER_assert(c > a && c > b);

        counter++;
    }

    // Ensure final conditions hold

    return 0;
}