#include <stdio.h>
#include <stdlib.h>

// SPDX-License-Identifier: Apache-2.0
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 3, "reach_error"); }
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

int calculate_value(int a, int b) {
    if (a <= 0 || b <= 0) {
        return -1;
    }
    return a * b;
}

int main() {
    int m, n;
    int loop_counter = 0;
    long long sum = 0;
    const int max_loops = 10;
    int result;

    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Ensuring m and n are within positive ranges
    assume_abort_if_not(m > 0 && n > 0);

    while (loop_counter < max_loops) {

        result = calculate_value(m, n);
        __VERIFIER_assert(result > 0);

        sum += result;
        loop_counter++;

        if (loop_counter == max_loops) {
            break;
        }
    }

    // Final assertion after the loop

    printf("Final sum: %lld\n", sum);
    return 0;
}