#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "unique-logic.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int n, a, b, result;
    long long f1, f2, k;

    // Inputs
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 5);

    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 5);

    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 5);

    // Initializations
    f1 = 0;
    f2 = 1;
    result = 0;

    k = 0;

    while (1) {
        if (!(k < n)) {
            break;
        }

        f2 = f1 + f2; // Fibonacci sequence logic
        f1 = f2 - f1;

        if ((f2 % a) == 0) {
            result += b;
        }

        k = k + 1;
    }

    __VERIFIER_assert(result >= 0);
    return 0;
}