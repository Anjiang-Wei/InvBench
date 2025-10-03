#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int n, result, sum = 0;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    for (int i = 0; i < n; ++i) {
        result = fibonacci(i);
        sum = sum + result;
    }

    __VERIFIER_assert(sum >= 0); // Assert that sum is non-negative

    return 0;
}