#include <assert.h>
#include <stdbool.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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
    int a, b, n;
    long long product = 1;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0 && b > 1);
    assume_abort_if_not(n >= 1);

    int i = 0;
    while (i < n) {
        // Multiply the number 'a' by 'b' consecutively 'n' times
        product = product * (a * b);
        i++;
    }

    // Final checks
    __VERIFIER_assert(i == n);

    return 0;
}