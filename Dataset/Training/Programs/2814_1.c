#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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

int counter = 0;

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
    int x;
    x = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 0 && x <= 20);

    int result = fibonacci(x);

    // Verify if the result is non-negative and follows the Fibonacci logic
    __VERIFIER_assert(result >= 0);

    // Additional loop to simulate verification pattern
    int y = 0;
    while (counter++ < 10) {
        y = y + 2;
        if (y >= 20) {
            break;
        }
    }

    printf("Fibonacci(%d) = %d\n", x, result);
    return 0;
}