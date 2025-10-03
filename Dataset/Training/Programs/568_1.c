#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program_example.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = 0, b = 0, k = 0;
    int target;
    target = __VERIFIER_nondet_int();
    assume_abort_if_not(target >= 5 && target <= 15);

    while (a < target) {
        b = b + a;
        a = a + 1;
        k = k + 2;

        // Asserting a relationship between variables after each iteration
        __VERIFIER_assert(k == 2 * a);
    }

    // Final relationship assertion after the loop

    printf("Final values - a: %d, b: %d, k: %d, target: %d\n", a, b, k, target);

    return 0;
}