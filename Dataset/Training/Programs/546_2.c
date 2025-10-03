#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b;
    int gcd = 0;

    // Assume a and b to be positive integers within a certain range
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0 && a <= 10);
    assume_abort_if_not(b > 0 && b <= 10);

    int max = (a > b) ? a : b;
    for (int i = 1; i <= max; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    // Let's add some verification conditions
    __VERIFIER_assert(a % gcd == 0 && b % gcd == 0);

    printf("GCD of %d and %d is %d\n", a, b, gcd);

    return 0;
}