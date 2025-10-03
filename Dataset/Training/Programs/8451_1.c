#include <stdio.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int a, b, n;
    long long result;

    // Inputs from a verifier with assumptions
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 50);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 50);
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 10);

    result = 0;
    int i = 0;

    while (i < n) {
        result = result + a * b;
        i++;
    }

    // Verify the result
    __VERIFIER_assert(result == a * b * n);

    // Print the result
    printf("Final result: %lld\n", result);

    return 0;
}