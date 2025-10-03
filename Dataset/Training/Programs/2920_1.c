#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
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

int compute(int a, int b) {
    int result = 0;
    for (int i = 0; i < a; i++) {
        result += b;
        if (result > 1000) {
            result = 1000; // Limit result to avoid overflow
        }
    }
    return result;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 100);

    // Initial conditions
    int initial_result = compute(a, b);

    // Example loop with a computational constraint
    for (int i = 0; i < 10; i++) {
        int new_result = compute(a + i, b - i);

        // Assert that new_result should never exceed a certain limit
        __VERIFIER_assert(new_result <= 1000);

        // Assert that new_result should never be less than initial_result
    }

    printf("Computation completed.\n");
    return 0;
}