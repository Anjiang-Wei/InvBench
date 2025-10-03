#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int sum;

    assume_abort_if_not(a >= 0 && b >= 0 && c >= 0);
    assume_abort_if_not(a <= 100 && b <= 100 && c <= 100);

    sum = a + b + c;

    // Ensure the sum does not exceed 200
    while (sum > 200) {
        if (a > 50) {
            a -= 10;
        } else if (b > 50) {
            b -= 10;
        } else if (c > 50) {
            c -= 10;
        } else {
            break; // Impossible to reduce further
        }
        sum = a + b + c;
    }

    printf("Adjusted values: a=%d, b=%d, c=%d, sum=%d\n", a, b, c, sum);

    __VERIFIER_assert(sum <= 200);

    return 0;
}