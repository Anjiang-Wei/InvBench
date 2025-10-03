#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern void abort(void);
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
extern int __VERIFIER_nondet_int(void);

int multiply_accumulate(int a, int b, int limit) {
    int sum = 0;
    int i;
    for (i = 0; i < limit; i++) {
        sum += a * b;
    }
    return sum;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int limit = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= -10 && a <= 10);
    assume_abort_if_not(b >= -10 && b <= 10);
    assume_abort_if_not(limit >= 0 && limit <= 10);

    int result;
    result = multiply_accumulate(a, b, limit);

    // Assert that multiplication and accumulation satisfy certain properties
    __VERIFIER_assert(result == a * b * limit);

    return 0;
}