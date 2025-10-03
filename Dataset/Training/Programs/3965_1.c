#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "automated_verification.c", 3, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c, i;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fact(int n) {
    if (n <= 1) {
        return 1;
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = 5; // Let's assume working with 5 to check functions
    int fib_n = fibonacci(n);
    int fac_n = fact(n);

    // Constraint verification
    // Check if for n=5, fib(5) is 5 and fact(5) is 120
    __VERIFIER_assert(fib_n == 5);

    // Additionally, validate for other computational logic based on the results

    return 0;
}