#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "new_program.c", 3, "reach_error");
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
    }
    }
    return;
}

int __VERIFIER_nondet_int();

int main() {
    int a = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 1 && a <= 10);
    assume_abort_if_not(n >= 2 && n <= 10);

    int result = 0;
    int i;

    for (i = 0; i < n; i++) {
        result += a;
    }

    int expected_result = a * n;
    __VERIFIER_assert(result == expected_result);

    printf("Sum of %d added %d times is %d (Expected: %d)\n", a, n, result, expected_result);

    return 0;
}