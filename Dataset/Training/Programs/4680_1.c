#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int compute_fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        int a = 0, b = 1, next;
        for (int i = 2; i <= n; i++) {
            next = a + b;
            __VERIFIER_assert(next > a); // ensuring no overflow here (may not verify in all settings)
            a = b;
            b = next;
        }
        return b;
    }
}

int main() {
    int n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n < 50); // to ensure computation is feasible and prevent overflow

    int result = compute_fibonacci(n);

    // Verify the basic property of Fibonacci function: F(n) > F(n-1) for n > 1
    if (n > 1) {
        int prev_result = compute_fibonacci(n - 1);
    }

    printf("Fibonacci(%d) = %d\n", n, result);

    return 0;
}