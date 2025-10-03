#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int factorial(int n) {
    if (n < 0) {
        return -1;
    }
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int x, y;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    if (x >= 0 && y >= 0 && x <= 10 && y <= 10) {
        int resultX = factorial(x);
        int resultY = factorial(y);

        __VERIFIER_assert(resultX >= 0 && resultY >= 0);

        int total = resultX + resultY;

        // Verification constraint: total should never exceed a certain value
        printf("Factorial of %d is %d\n", y, resultY);
        printf("Sum of factorials is %d\n", total);

        return 0;
    }

    return -1;
}