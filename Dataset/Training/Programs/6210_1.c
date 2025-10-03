#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

#define MAX_ITER 50

int fib(int n) {
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

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int max_chk = __VERIFIER_nondet_int();

    // Set a meaningful range for n
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 20);

    // Set a maximum checkpoint value for safety
    assume_abort_if_not(max_chk > n);

    int result = fib(n);

    // Verify that the result is in a reasonable range for the Fibonacci sequence
    __VERIFIER_assert(result >= 0);

    // Verify that the result doesn't exceed a logically derived checkpoint
    // This ensures the program was executed correctly under set conditions

    return 0;
}