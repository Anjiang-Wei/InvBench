#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-program.c", 8, "reach_error"); }

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
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int sum = 0;
    int i = 1;

    // Assume some reasonable conditions for a, b, and c
    assume_abort_if_not(a >= 0 && b >= 1 && c >= 0);

    while (i <= b) {
        sum += a;
        i++;
    }

    // The sum should be exactly a * b after the loop

    // Additional computation to verify some logic
    int result = sum * c;
    __VERIFIER_assert(result >= 0); // Since sum and c should be non-negative

    // Print statements are optional, they don't affect verification
    printf("Sum: %d, Result: %d\n", sum, result);

    return 0;
}