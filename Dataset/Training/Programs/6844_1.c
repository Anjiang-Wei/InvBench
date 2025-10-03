#include <assert.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int compute_fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0;
    int b = 1;
    int c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Assume a reasonable condition for n, such as being non-negative
    if (n < 0 || n > 20) {
        return 0;
    }

    int result = compute_fibonacci(n);

    // Verify that for any non-negative n, the Fibonacci number is non-negative
    __VERIFIER_assert(result >= 0);

    return 0;
}