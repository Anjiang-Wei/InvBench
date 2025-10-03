#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }
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

int main() {
    int a, n;
    long long sum_even = 0;
    long long sum_odd = 0;
    long long total_sum = 0;

    a = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    if (n <= 0 || n > 1000000) {
        return 0;
    }
    assume_abort_if_not(a > 0);

    for (int i = 0; i < n; i++) {
        int current_value = a + i;

        if (current_value % 2 == 0) {
            sum_even += current_value;
        } else {
            sum_odd += current_value;
        }

        total_sum += current_value;
    }

    __VERIFIER_assert(total_sum == sum_even + sum_odd);
    printf("Total Sum: %lld, Sum Even: %lld, Sum Odd: %lld\n", total_sum, sum_even, sum_odd);

    return 0;
}