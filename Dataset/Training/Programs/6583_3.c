#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}
extern int __VERIFIER_nondet_int(void);

int fibonacci(int n, int max) {
    int a = 0, b = 1, temp = 0;

    if (n == 0) {
        return a;
    }
    if (n == 1) {
        return b;
    }

    for (int i = 2; i <= n; ++i) {
        b = temp;
    }

    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int max_value = __VERIFIER_nondet_int();

    // Limit constraints
    if (n < 0 || n > 20) {
        return 0;
    }
    if (max_value < 20 || max_value > 2000) {
        return 0;
    }

    int result = fibonacci(n, max_value);

    // Ensure the result does not exceed maximum allowed value
    __VERIFIER_assert(result >= 0 && result <= max_value);

    printf("Fibonacci of %d is %d with max %d\n", n, result, max_value);

    return 0;
}