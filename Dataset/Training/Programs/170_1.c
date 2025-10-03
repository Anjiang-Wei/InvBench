#include <stdio.h>
#include <stdlib.h>

// External abort and assertion mechanism
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new-program.c", 5, "reach_error"); }

// Functions for assumption and assertion
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        ;
    }
    }
    return;
}

// Nondeterministic input generation
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1);
    assume_abort_if_not(n <= 1000);

    int sum = 0;
    int prod = 1;

    for (int i = 1; i <= n; i++) {
        int val = __VERIFIER_nondet_int();
        assume_abort_if_not(val >= 1);
        assume_abort_if_not(val <= 10);

        sum += val;
        prod *= val;

        if (sum < i) {
            reach_error();
        }

        int max_sum = i * 10; // max possible sum for i elements
        __VERIFIER_assert(sum <= max_sum);
    }

    printf("Final Sum: %d, Final Product: %d\n", sum, prod);

    // Ensuring valid range after loop

    return 0;
}