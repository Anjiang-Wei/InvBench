#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    int a, b, result;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume some initial conditions
    assume_abort_if_not(a >= 0 && b >= 0 && b < 10);

    result = 0;
    int i = 0;

    // Loop with some logic
    while (i < b) {
        result += a;
        if (result > 100) {
            result = result % 10; // Keep the result bounded
        }
        i++;
    }

    // Check some post-conditions
    __VERIFIER_assert(result <= 100);

    return 0;
}