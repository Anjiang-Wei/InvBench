#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void reach_error(void) {
    printf("Error reached\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10); // Constraint: n is between 1 and 10

    int a = 1;
    int b = 1;
    int sum = 0;
    int i;

    for (i = 0; i < n; i++) {
        int tmp = a + b;
        a = b;
        b = tmp;
        sum += tmp;
    }

    // Condition to verify: sum is greater than 'n' after n iterations
    __VERIFIER_assert(sum > n);

    return 0;
}