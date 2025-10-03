// Example Program 4
#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { __assert_fail("0", "example_program4.c", 3, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = 0;

    // Ensure a and b are non-negative and smaller than a reasonable bound
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);
    assume_abort_if_not(a <= 100);
    assume_abort_if_not(b <= 100);

    int sum = 0;
    for (int i = 0; i < a; i++) {
        sum += i;
        if (sum > a * b) {
            break;
        }
    }

    // Compute product using repeated addition
    for (int j = 0; j < b; j++) {
        c += a;
    }

    // Assert that c is the product of a and b
    __VERIFIER_assert(c == a * b);

    return 0;
}