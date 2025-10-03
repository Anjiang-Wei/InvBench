#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int();
unsigned int __VERIFIER_nondet_uint();

int calculate_fibonacci(int n) {
    int a = 0, b = 1, fib = 0, i;
    if (n == 0) {
        return a;
    }
    for (i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return b;
}

int main() {
    unsigned int target, n, sum;
    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 0 && n <= 30); // constraining n for practical computation
    target = __VERIFIER_nondet_int();
    assume_abort_if_not(target >= 0);

    sum = 0;
    unsigned int counter = 0;

    // Calculate Fibonacci numbers and sum them until target or upper limit is reached
    while (sum < target && counter < n) {
        int fib = calculate_fibonacci(counter);
        sum += fib;
        ++counter;
    }

    __VERIFIER_assert(sum >= target || counter == n); // Ensures termination condition is legitimate
    return 0;
}