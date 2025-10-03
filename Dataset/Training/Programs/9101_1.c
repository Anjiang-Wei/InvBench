#include <stdio.h>
extern void abort(void);
void reach_error() { __assert_fail("0", "custom_program.c", __LINE__, "reach_error"); }
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
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
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100);
    assume_abort_if_not(a >= 0 && b >= 0);

    int sum = 0;
    int i;

    for (i = 0; i < n; i++) {
        // Compute some dynamic condition or operation
        if ((i % 2) == 0) {
            sum = sum + a;
        } else {
            sum = sum + b;
        }
    }

    // Check if sum satisfies specific conditions after loop execution
    __VERIFIER_assert(sum >= n / 2 * a && sum >= n / 2 * b);

    printf("Sum after loop: %d\n", sum);
    return 0;
}

unsigned int __VERIFIER_nondet_int() {
    // A simple deterministic number for now to simulate the nondeterministic function
    return 5;
}