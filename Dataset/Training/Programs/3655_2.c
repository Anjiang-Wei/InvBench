#include <assert.h>
#include <stdio.h>
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void reach_error(void) { assert(0); }

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

/* A C program that verifies the relationship between two sequences
   initially defined by a mathematical relationship.
   The program is intended for automated analysis and verification.
*/

int main() {
    int a, b, c, sum;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);
    assume_abort_if_not(c >= 0);
    assume_abort_if_not(a % 2 == 0 && b % 3 == 0); // assume initial conditions

    sum = 0;

    while (b > 0 && a > 0) {
        sum += (a % 4) * (b % 5);
        b = b - (b / 3);
        c++;
    }

    __VERIFIER_assert(a * b <= c); // verify relation after loop

    printf("Final state: a=%d, b=%d, c=%d, sum=%d\n", a, b, c, sum);
    return 0;
}