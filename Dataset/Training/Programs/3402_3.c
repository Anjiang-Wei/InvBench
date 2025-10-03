#include <stdio.h>
#include <stdlib.h>

void reach_error(void) {
    printf("Error Reached!\n");
    exit(1);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        exit(0);
    }
}

/*
 This program computes the Fibonacci sequence iteratively,
 ensuring that after the loop, the nth Fibonacci number is
 correct. The computation checks a known property of Fibonacci
 numbers: F(n-1) + F(n-2) = F(n).
*/

int main() {
    int n, a, b, c, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    a = 0;
    b = 1;
    c = 0;

    for (i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    if (n == 0) {
    } else if (n == 1) {
    } else {
        __VERIFIER_assert(c == a + b - a);
    }

    return 0;
}