#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int compute(int a, int b, int n) {
    int result = a;
    for (int i = 0; i < n; i++) {
        result += b;
        if (result > 100) {
            result -= 100;
        }
    }
    return result;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 50);
    assume_abort_if_not(b >= 0 && b <= 50);
    assume_abort_if_not(n >= 0 && n <= 20);

    int result = compute(a, b, n);

    // Verification condition: result should never be negative
    __VERIFIER_assert(result >= 0);

    return 0;
}