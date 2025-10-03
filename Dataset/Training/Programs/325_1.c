#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, tmp, i;
    for (i = 2; i <= n; ++i) {
        tmp = a + b;
        a = b;
        b = tmp;
    }
    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Introduce a constraint for n to be non-negative
    if (n < 0 || n > 20) {
        return 0;
    }

    int fib = fibonacci(n);
    int sum = 0;
    int current_index = 0;

    // Accumulate until a condition is met with a loop
    while (__VERIFIER_nondet_bool() && current_index <= n) {
        sum += current_index;
        current_index++;
    }

    __VERIFIER_assert(sum >= 0 && sum <= n * (n + 1) / 2);

    printf("Fibonacci number is: %d\n", fib);
    printf("Accumulated sum is: %d\n", sum);

    return 0;
}