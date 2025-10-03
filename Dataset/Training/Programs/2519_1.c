#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int prev = 0;
        int curr = 1;
        int temp;
        for (int i = 2; i <= n; ++i) {
            temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);

    int result = fibonacci(n);

    // check if the 10th Fibonacci number is less than 100 (specific verification)
    if (n == 10) {
        __VERIFIER_assert(result < 100);
    }

    // Non-deterministic loop demonstrating an iterative pattern
    int sum = 0;
    while (__VERIFIER_nondet_bool()) {
        int value = __VERIFIER_nondet_int();
        assume_abort_if_not(value >= 0 && value <= 10);
        sum += value;
        if (sum > 50) {
            break;
        }
    }

    // Final assertion adding a constraint for verification tools

    return 0;
}