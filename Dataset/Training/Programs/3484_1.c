#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int N = __VERIFIER_nondet_int();

    assume_abort_if_not(N >= 0 && N < 20); // Ensure N is within a reasonable range to avoid stack overflow

    int i, sum = 0;
    for (i = 0; i < N; i++) {
        int f = fib(i);
        sum += f;
    }

    __VERIFIER_assert(sum >= 0); // The sum of non-negative Fibonacci numbers should be non-negative

    return 0;
}